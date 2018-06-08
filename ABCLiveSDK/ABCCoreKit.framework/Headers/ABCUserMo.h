//
//  ABCUserMo.h
//  ABCLiveKit
//
//  Created by bing on 2017/5/16.
//  Copyright © 2017年 北京暄暄科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ABCUserMo : NSObject

@property(nonatomic,strong) NSString *avataUrl;
@property(nonatomic,strong) NSString *nickName;
@property(nonatomic,strong) NSString *userId;
@property(nonatomic,strong) NSString *openId;
@property(nonatomic,assign) NSInteger openIdType;
@property(nonatomic,assign) NSInteger type;


//@property(nonatomic,strong) NSString *avataUrl;
//@property(nonatomic,strong) NSString *avatar_url;
//@property(nonatomic,strong) NSString *nickname;
//@property(nonatomic,strong) NSString *id;
//@property(nonatomic,strong) NSString *token;
//@property(nonatomic,strong) NSString *phoneNumber;
//@property(nonatomic,strong) NSString *deviceId;
//@property(nonatomic,assign) int gender;
//@property(nonatomic,strong) NSString *school;
//@property(nonatomic,strong) NSString *grades;
//@property(nonatomic,strong) NSString *phone_number;
//@property(nonatomic,strong) NSString *password;
//@property(nonatomic,strong) NSString *create_time;
//@property(nonatomic,strong) NSString *update_time;
//@property(nonatomic,strong) NSString *openid;
//@property(nonatomic,strong) NSString *signature;
//@property(nonatomic,assign) NSInteger openid_type;

@end
