//
//  ABCLiveUserMo.h
//  ABCCoreKit
//
//  Created by bing on 2017/8/11.
//  Copyright © 2017年 北京暄暄科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@class ABCUserMo;

typedef enum : NSUInteger {
    ABCUserRoomStatus_NOMAL,
    ABCUserRoomStatus_HAND_UP,
    ABCUserRoomStatus_INMIC,
} ABCUserRoomStatus;

@interface ABCLiveUserMo : NSObject

@property(nonatomic,strong) NSString *uid;//笔声用户id
@property(nonatomic,strong) NSString *uname;
@property(nonatomic,strong) NSString *avatar;
@property(nonatomic,assign) NSInteger ustatus;/* ustatus:  0 //正常    1 //  举手 申请发   2, 上线/上麦  */

@property(nonatomic,assign) NSInteger roleType;/*1 学生, 2 老师, 5 管理员 */
@property(nonatomic,assign) NSInteger device;// 1:pc 2:android 3:ios 默认服务端那里是1
@property(nonatomic,assign) NSInteger audioStreamStatus;
@property(nonatomic,assign) NSInteger videoStreamStatus;
@property(nonatomic,assign) NSInteger desktopStreamStatus;
@property(nonatomic,assign) NSInteger forbidChatStatus;
@property(nonatomic,assign) NSInteger forbidSpeakStatus;
@property(nonatomic,assign) NSInteger orderValue;
@property(nonatomic,strong) NSString *userExt;
@property(nonatomic,assign) BOOL isShared;

-(instancetype) initWithUserMo:(ABCUserMo *) userMo;

@end
