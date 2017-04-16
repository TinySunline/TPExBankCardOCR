//
//  TPExBankCardOCR.h
//  Pods
//
//  Created by kingdomrain on 2017/4/15.
//
//

#import <Foundation/Foundation.h>
#import <JavaScriptCore/JSExport.h>
#import <UIKit/UIKit.h>


@protocol TPExBankCardOCRProtocol<JSExport>
@property(nonatomic, strong) JSValue *success;
@property(nonatomic, strong) JSValue *error;

/**
 *  银行卡扫描
 */
-(void)camera;

@end

@interface TPExBankCardOCR : NSObject<TPExBankCardOCRProtocol>
@property (nonatomic , strong) UIViewController *viewController;

@end
