//
//  EXOCRBankRecoManager.h
//  ExBankCardSDK
//
//  Created by kubo on 16/9/2.
//  Copyright © 2016年 kubo. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "EXOCRBankCardInfo.h"

/**
 *	@brief 银行卡识别回调EXOCRCompletedBankBlock, EXOCRCanceledBlock, EXOCREXOCRFailedBlock
 *
 *	@discussion 用来设定异步调用的回调
 */
typedef void (^EXOCRCompletedBankBlock)(int statusCode, EXOCRBankCardInfo *bankInfo);
typedef void (^EXOCRCanceledBlock)(int statusCode);
typedef void (^EXOCRFailedBlock)(int statusCode, UIImage *recoImg);

@interface EXOCRBankRecoManager : NSObject
/**
 *	@brief 获取EXOCRBankRecoManager实例化对象
 *  @return EXOCRBankRecoManager对象
 */
+(instancetype)sharedManager:(UIViewController *)vc;

/**
 * @brief 静态图片识别方法
 * @param image - 待识别静态图像
 * @param completedBlock - 识别成功回调，获取识别结果EXOCRBankCardInfo对象
 * @param EXOCRFailedBlock - 识别失败回调
 */
-(void)recoBankFromStillImage:(UIImage *)image
                  OnCompleted:(EXOCRCompletedBankBlock)completedBlock
                     OnFailed:(EXOCRFailedBlock)EXOCRFailedBlock;

/**
 * @brief 方向设置，设置扫描页面支持的识别方向
 * @param orientationMask - 默认为UIInterfaceOrientationMaskAll
 */
-(void)setRecoSupportOrientations:(UIInterfaceOrientationMask)orientationMask;

/**
 * @brief 扫描页面调用方式设置，设置扫描页面调用方式
 * @param bByPresent - 是否以present方式调用，默认为NO，YES-以present方式调用，NO-以sdk默认方式调用(push或present)
 */
-(void)displayScanViewControllerByPresent:(BOOL)bByPresent;

/**
 * @brief 结果设置，银行卡号是否包含空格
 * @param bSpace - 默认为YES
 */
-(void)setSpaceWithBANKCardNum:(BOOL)bSpace;

/**
 *	@brief 获取sdk版本号
 *  @return sdk版本号
 */
+(NSString *)getSDKVersion;

/**
 *	@brief 获取识别核心版本号
 *  @return 识别核心版本号
 */
+(NSString *)getKernelVersion;

#pragma - mark 默认扫描视图
/**
 * @brief 调用银行卡扫描识别(若自定义扫描视图，请使用recoBankFromStreamByCustomScanView方法调用识别)
 * @param completedBlock - 识别完成回调，获取识别结果EXOCRBankCardInfo对象
 * @param EXOCRCanceledBlock - 识别取消回调
 * @param EXOCRFailedBlock - 识别失败回调
 */
-(void)recoBankFromStreamOnCompleted:(EXOCRCompletedBankBlock)completedBlock
                          OnCanceled:(EXOCRCanceledBlock)EXOCRCanceledBlock
                            OnFailed:(EXOCRFailedBlock)EXOCRFailedBlock;

/**
 * @brief 扫描页设置，是否显示logo
 * @param bDisplayLogo - 默认为YES
 */
-(void)setDisplayLogo:(BOOL)bDisplayLogo;

/**
 * @brief 扫描页设置，是否开启本地相册识别
 * @param bEnablePhotoRec - 默认为YES
 */
-(void)setEnablePhotoRec:(BOOL)bEnablePhotoRec;

/**
 * @brief 扫描页设置，扫描框颜色
 * @param rgbColor - rgb颜色值(例:0xffffff)
 * @param alpha - 透明度(例：0.8f, 0-1之间)
 */
-(void)setScanFrameColorRGB:(long)rgbColor andAlpha:(float)alpha;

/**
 * @brief 扫描页设置，扫描字体颜色
 * @param rgbColor - rgb颜色值(例:0xffffff)
 */
-(void)setScanTextColorRGB:(long)rgbColor;

/**
 * @brief 扫描页设置，扫描提示文字
 * @param tipStr - 提示文字
 */
-(void)setScanTips:(NSString *)tipStr;

/**
 * @brief 扫描页设置，扫描提示文字字体名称及字体大小
 * @param fontName - 字体名称
 * @param fontSize - 字体大小
 */
-(void)setScanTipsFontName:(NSString *)fontName andFontSize:(float)fontSize;

#pragma mark - 自定义扫描视图
/**
 *	@brief 设置自定义扫描视图（若自定义扫描视图，其他扫描页设置接口将无效）
 *         自定义扫描视图frame须与竖屏屏幕大小一致
 *         建议：1.自定义扫描视图frame设置为[UIScreen mainScreen].bounds(须保证width小于height)
 *              2.自定义扫描视图扫描框宽高比设置为720:454，以达到最佳识别效果
 *
 *  @return YES-设置自定义扫描视图成功，NO-设置自定义扫描视图失败
 *  @param customScanView - 自定义扫描试图
 */
-(BOOL)setCustomScanView:(UIView *)customScanView;

/**
 *	@brief 退出扫描识别控制器（仅在设置自定义扫描视图成功后生效）
 */
- (void)dismissScanViewControllerAnimated:(BOOL)animated;

/**
 *	@brief 闪光灯开启与关闭（仅在设置自定义扫描视图成功后生效）
 *  @param bMode - 闪光灯模式，YES-打开闪光灯，NO-关闭闪光灯
 */
-(void)setFlashMode:(BOOL)bMode;

/**
 * @brief 调用银行卡扫描识别(若默认扫描视图，请使用recoBankFromStreamOnCompleted:OnCanceled:OnFailed:方法调用识别)
 */
-(void)recoBankFromStreamByCustomScanView;
@end
