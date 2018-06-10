//
//  ABCUIKit.h
//  ABCLiveKit
//
//  Created by bing on 2017/8/14.
//  Copyright © 2017年 北京暄暄科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ABCCoreKit/ABCCoreKit.h>
#import "ABCInteractiveViewController.h"
#import "ABCLivingViewController.h"
#import "ABCViewCrtlDelegate.h"

@protocol ABCUIKitDelegate<NSObject>

- (void)finishCourse:(NSInteger)courseId;

@end

@interface ABCUIKit : NSObject

@property(nonatomic, strong) NSString *qqAppKey;//qq appid
@property(nonatomic, strong) NSString *qqSecret;//qq secret

@property(nonatomic, strong) NSString *wechatAppKey; //微信 appid
@property(nonatomic, strong) NSString *wechatSecret; //微信 secret

@property(nonatomic, assign) BOOL showLivingPromptCover;//显示直播新手指引
@property(nonatomic, assign) BOOL showInteractivePromptCover;//显示新手指引

@property(nonatomic, weak) id<ABCUIKitDelegate> abcUIKitDelegate;

+ (instancetype)shareABCUIKit;

@end
