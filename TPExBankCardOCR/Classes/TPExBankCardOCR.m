
//
//  TPExBankCardOCR.m
//  Pods
//
//  Created by kingdomrain on 2017/4/15.
//
//

#import "TPExBankCardOCR.h"
#import <ExBankCardSDK/ExBankCardSDK.h>

@implementation TPExBankCardOCR
@synthesize success;
@synthesize error;


-(instancetype)init{
    if (self=[super init]) {
        Class TinyPlus=NSClassFromString(@"TinyPlus");
        if(TinyPlus){
            id tinyPlusInPod  =  [[TinyPlus alloc] init];
            if([tinyPlusInPod respondsToSelector:@selector(getViewController)]){
                self.viewController =[tinyPlusInPod performSelector:@selector(getViewController)];
            }
        }
    }
    return self;
}

-(void)camera{
//    NSLog(@"调银行卡");
    EXOCRBankRecoManager *manager =[EXOCRBankRecoManager sharedManager:self.viewController];
    [manager setDisplayLogo:NO];
    [manager displayScanViewControllerByPresent:YES];       //以present的方式展示
    [manager recoBankFromStreamOnCompleted:^(int statusCode, EXOCRBankCardInfo *bankInfo) {
        NSLog(@"Completed");
        NSLog(@"%@", [bankInfo toString]);
        NSString *data = [NSString stringWithFormat:@"{\"cardNum\":\"%@\",\"bankName\":\"%@\",\"validDate\":\"%@\",\"cardName\":\"%@\",\"cardType\":\"%@\"}",bankInfo.cardNum,bankInfo.bankName,bankInfo.validDate,bankInfo.cardName,bankInfo.cardType];
        [self.success callWithArguments:@[data]];
        self.success = nil;
        self.error = nil;
        
    } OnCanceled:^(int statusCode) {
        NSLog(@"Canceled");
        [self.error callWithArguments:@[@"取消"]];
        self.success = nil;
        self.error = nil;
        
    } OnFailed:^(int statusCode, UIImage *recoImg) {
        NSLog(@"Failed");
        [self.error callWithArguments:@[@"失败"]];
        self.success = nil;
        self.error = nil;
    }];
}


-(void)dealloc{
//    NSLog(@"TPExBankCardOCR 销毁");
}




@end
