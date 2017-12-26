//
//  ZTPartnerSnsManager.h
//  ZTPartner
//
//  Created by 钟理康 on 2017/12/12.
//  Copyright © 2017年 钟理康. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ZTPartnerData.h"

/**
 网络请求结果状态码
 
 */
typedef enum {
    ZTPartnerResponseCodeSuccess                 = 200,        //成功
    ZTPartnerResponseCodeTokenInvalid            = 400,        //授权用户token获取失败
    ZTPartnerResponseCodeGroupId                 = 600,        //门店ID为空
    ZTPartnerResponseCodeSecretKey               = 601,        //密钥为空
    ZTPartnerResponseCodeCsid                    = 602,        //端口ID为空
} ZTPartnerResponseCode;


@interface ZTPartnerResponseEntity : NSObject

/**
 代表发送结果，ZTPartnerResponseCodeSuccess代表成功，参看上面的定义
 
 */
@property (nonatomic, assign) ZTPartnerResponseCode responseCode;

@end


typedef void (^ZTPartnerSnsManagerCompletion)(ZTPartnerResponseEntity * response);

@interface ZTPartnerSnsManager : NSObject

+(ZTPartnerSnsManager *)defaultManager;

///---------------------------------------
/// @name 属性
///---------------------------------------

@property (nonatomic, copy) ZTPartnerSnsManagerCompletion completion;

/**
 通过`ZTPartnerData`对象，可以设置门店ID、密钥、端口号等属性
 */
@property (nonatomic, retain) ZTPartnerData *partnerData;

/**
 跳转控制器的方式
 
 */
@property (assign, nonatomic) BOOL isPresentInController;

/** 跳转股东分红界面的方式
 
 @param isPresentInController 如果YES代表弹出(present)到当前UIViewController，否则push到UIViewController的navigationController
 @param presentedController 点击后弹出UIViewController对象
 @param completion 完成之后的回调对象，返回的response参数表示成功与否
 
 */
-(void)postIsPresentInController:(BOOL)isPresentInController
             PresentedController:(UIViewController *)presentedController
                      completion:(ZTPartnerSnsManagerCompletion)completion;

@end
