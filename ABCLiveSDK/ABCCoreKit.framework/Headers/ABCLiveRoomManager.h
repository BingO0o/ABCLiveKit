//
//  ABCLiveRoomManager.h
//  ABCLiveKit
//
//  Created by bing on 2017/5/12.
//  Copyright © 2017年 北京暄暄科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABCLiveVideoData.h"
#import "ABCBaseManager.h"

@interface ABCLiveRoomManager : ABCBaseManager

@property(nonatomic, assign) BOOL isAutoMic;//是否自动请求上麦

/**
 * 初始化ABCLiveRoomManager
 *
 *  @param rid    房间id
 *  @param roleType ABCRoleType
 *
 *  @return ABCLiveRoomManager
 */
-(instancetype) initABCLiveRoomManager:(NSString *) rid roleType:(ABCRoleType) roleType isrecord:(NSInteger) isrecord;

/**
 * 连接
 */
-(void) connect;

/**
 * 重新连接白板服务器
 */
-(void) reConnectToWbServer;

/**
 *  释放
 */
-(void) managerRelease;

/**
 *  结束会议
 */
-(void) sendFinishMeeting;

/**
 *  设置远端摄像头显示view
 *
 *  @param videoData video信息
 */
-(void) setupRemoteVideo:(ABCLiveVideoData *) videoData;
/**
 *  设置本地摄像头显示view
 *
 *  @param videoData video信息
 */
-(void) setupLocalCameraVideo:(ABCLiveVideoData *) videoData;

///**
// * 禁用视频
// */
//-(void) disableVideo;
///**
// *  开启视频
// */
//-(void) enableVideo;

/**
 *  允许某个用户上下麦
 *
 *  @param uid  用户id
 *  @param isUp 上麦下麦
 */
-(void) accreditSpeak:(NSString *) uid isUp:(BOOL) isUp;

/**
 *  请求上下麦
 *
 *  @param isUp 上下麦
 */
-(void) requestSpeak:(BOOL) isUp;

/**
 *  邀请用户发言
 *
 *  @param userId          用户id
 */
-(void) inviteUserSpeak:(NSString *) userId;

/**
 *  禁止用户发言/取消
 *
 *  @param userId   用户id
 *  @param isForBid 禁止与否
 */
-(void) forbidUserSpeak:(NSString *) userId isForbid:(BOOL) isForBid;

/**
 *  禁止用户聊天/取消
 *
 *  @param userId   用户id
 *  @param isForBid 禁止与否
 */
-(void) forbidUserChat:(NSString *) userId isForbid:(BOOL) isForBid;

/**
 *  同意邀请发言
 *
 *  @param isApprove 是否同意
 *  @param userId 邀请的用户id
 */
-(void) approveUserInvite:(BOOL) isApprove toUserId:(NSString *) userId;

/**
 *  切换前后置摄像头
 */

-(void) switchCamera;

/**
 *  开启视频
 *
 *  @param videoData video信息
 */
-(void) openCamera:(ABCLiveVideoData *) videoData;

/**
 *  关闭视频
 */
-(void) closeCamera;

/**
 *  设置是否打开mic
 *
 *  @param isOpenMic 是否打开
 */
-(void) setOpenMic:(BOOL) isOpenMic;

/**
 *  踢出学生
 *
 *  @param uid 用户uid
 */
-(void) kickedOutStudent:(NSString *) uid;

/**
 *  发送im消息
 *
 *  @param msg 消息内容
 */
-(void) sendMessage:(NSString *) msg;

/**
 *  根据用户id获取用户信息(只存储部分上麦用户)
 *
 *  @param userId 用户id
 */
-(ABCLiveUserMo *) getLiveUserMoById:(NSString *) userId;

/**
 *  根据用户id获取用户是否可以聊天权限（人员列表中，以人员列表为准）
 *
 *  @param userId 用户id
 */
-(BOOL) chatPermission:(NSString *) userId;

/**
 *  根据用户id获取用户是否可以上麦权限（人员列表中，以人员列表为准）
 *
 *  @param userId 用户id
 */
-(BOOL) speakPermission:(NSString *) userId;

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

#pragma mark - 白板
/**
 * 共享某个人的白板
 * uid为空表示停止共享
 */
-(void)sendWhiteboardShare:(NSString *)whiteboardid __attribute__((unavailable));

/**
 * 切换白板
 */
-(void)sendSwitchWBShare __attribute__((unavailable));

@end
