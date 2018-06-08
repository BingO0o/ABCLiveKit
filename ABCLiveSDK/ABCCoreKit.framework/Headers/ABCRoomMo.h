//
//  ABCRoomMo.h
//  ABCCoreKit
//
//  Created by bing on 2017/8/14.
//  Copyright © 2017年 北京暄暄科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ABCRoomMo : NSObject

@property (nonatomic, strong) NSString  *name; //直播间名字

@property (nonatomic, strong) NSString  *creator_id; //直播间创建者id (笔声用户id)

@property (nonatomic, strong) NSString  *room_id; //直播间id


@property (nonatomic, assign) NSInteger status; //

@property (nonatomic, assign) NSInteger type; //

@property (nonatomic, assign) NSInteger layout; //

@property (nonatomic, assign) NSInteger live_type; //开课类型

@property (nonatomic, strong) NSString  *background_img_url; // 封面背景地址

@property (nonatomic, strong) NSString  *create_time; //创建时间

@property (nonatomic, strong) NSString  *update_time; //更新时间

@property (nonatomic, strong) NSString  *last_visit_time; //

@property (nonatomic, strong) NSString  *show_room_id; //

@property (nonatomic, strong) NSString  *shareUrl; //

@property (nonatomic, strong) NSString  *shareContent; //

@property (nonatomic, strong) NSString  *shareTitle; //

@property (nonatomic, assign) NSInteger abcPenType; //1：笔声智能笔 2：equil 3:笔声智能笔2代

@property (nonatomic, assign) BOOL isSuperManager; //班主任。超级管理员

@property (nonatomic, assign) long long endTime; //结束时间

@property (nonatomic, assign) BOOL isHost;

@property (nonatomic, strong) NSMutableDictionary  *dicExtra; //

@property (nonatomic, assign) BOOL isRecord; //是否录制

@end
