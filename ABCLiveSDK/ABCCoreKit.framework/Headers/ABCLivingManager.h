//
//  ABCLivingManager.h
//  ABCLiveKit
//
//  Created by bing on 2017/5/25.
//  Copyright © 2017年 北京暄暄科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABCBaseManager.h"

@interface ABCLivingManager : ABCBaseManager

@property (nonatomic, strong, nullable) UIImage *mutedImage;

@property (nonatomic, assign) ABCVideoResolution videoResolution;//default ABCVideoResolutionMid

/**
 *  初始化ABCLivingManager
 *
 *  @param rid    房间id
 *  @param isPush 是否是主播
 *
 *  @return ABCLivingManager
 */
-(instancetype) initABCLivingManager:(NSString *) rid isPush:(BOOL) isPush isSuperManager:(BOOL) isSuperManager isrecord:(NSInteger)isrecord;

/**
 *  切换用户
 *
 *  @param openId    openid
 *  @param nickName  nickName
 *  @param avatarUrl 用户头像
 *  @param success   成功回调
 *  @param fail      失败回调
 */
-(void) resetUserByOpenid:(NSString *) openId
                 nickName:(NSString *) nickName
                avatarUrl:(NSString *) avatarUrl
                  success:(void (^)(id responseObject))success
                  failure:(void (^)(ABCErrorCode errorCode,NSString *strMsg))fail;

/**
 *  连接到直播间
 */
-(void) connectToRoom;

/**
 *  重新连接到白板服务器（重连失败后手动连接）
 */
-(void) reConnectToWbServer;

/**
 *  设置观看或者直播的view
 *
 *  @param videoView UIView
 */
-(void) setLivingView:(UIView *) videoView;

/**
 *  切换摄像头
 */
-(void) switchCamera;

/**
 *  开启美颜
 *
 *  @param isEnable 默认YES开启
 */
-(void) setBeautyEnabled:(BOOL) isEnable;

/**
 *  开始直播
 */
-(void) startLiving;


/**
 *  结束直播
 */
-(void) stopLiving;

/**
 *  释放manager
 */
-(void) managerRelease;

/**
 *  结束直播间，所有用户会在onStatusChange 中回调ABCStatusCode_FinishMeeting
 */
-(void) sendFinishMeeting;

/**
 *  发送im消息
 *
 *  @param msg 消息内容
 */
-(void) sendMessage:(NSString *) msg;

/**
 *  踢出用户
 *
 *  @param uid 用户id
 */
-(void) kickedOutStudent:(NSString *) uid;

/**
 *  禁止用户聊天/取消
 *
 *  @param userId   用户id
 *  @param isForBid 禁止与否
 */
-(void) forbidUserChat:(NSString *) userId isForbid:(BOOL) isForBid;

-(ABCLiveUserMo *) getLiveUserMoById:(NSString *) userId;

#pragma mark - 答题卡
/**
 * 发送答题卡
 */
-(void) sendQuestionCard:(NSInteger) type selectcount:(NSInteger) selectcount answers:(NSString *) answers;

/**
 * 发送停止答题卡
 */
-(void) sendStopQuestionCard;

/**
 * 请求统计结果
 */
-(void) sendGetAnserStatistics;

/**
 * 发送答案
 */
-(void) sendQuestionAnswers:(NSString *)answers seq:(NSInteger)seq;

@end
