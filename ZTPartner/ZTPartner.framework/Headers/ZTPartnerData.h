//
//  ZTPartnerData.h
//  ZTPartner
//
//  Created by 钟理康 on 2017/12/12.
//  Copyright © 2017年 钟理康. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 门店ID、密钥、端口号为APP当前登录账号所在门店、端口，密钥是添加门店时固定分配的随机字符串。
 
 */

@interface ZTPartnerData : NSObject

/**
 门店ID
 
 */
@property (copy, nonatomic) NSString *groupId;

/**
 密钥（添加门店时自动分配）
 
 */
@property (copy, nonatomic) NSString *secretKey;

/**
 端口ID
 
 */
@property (copy, nonatomic) NSString *csid;

/**
 获取默认的`ZTPartnerData`对象
 
 */
+ (ZTPartnerData *)defaultData;

@end
