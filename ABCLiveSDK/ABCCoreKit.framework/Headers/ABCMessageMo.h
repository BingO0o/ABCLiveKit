//
//  ABCMessageMo.h
//  ABCCoreKit
//
//  Created by bing on 2017/8/12.
//  Copyright © 2017年 北京暄暄科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ABCMessageMo : NSObject

@property (nonatomic, strong) NSString *fuid; // uid
@property (nonatomic, strong) NSString *userName; // username
@property (nonatomic, strong) NSString *avatar; // 头像url
@property (nonatomic, strong) NSString *msg; // 消息内容
@property (nonatomic, assign) long long     time;
@property(nonatomic, assign) NSInteger type;//0 普通消息 1系统消息
@property(nonatomic, assign) NSInteger action;//1 举手

@end
