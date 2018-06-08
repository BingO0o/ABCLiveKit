//
//  ABCLiveRoomDelegate.h
//  ABCLiveKit
//
//  Created by bing on 2017/5/25.
//  Copyright © 2017年 北京暄暄科技有限公司. All rights reserved.
//

#ifndef ABCLiveRoomDelegate_h
#define ABCLiveRoomDelegate_h


#endif /* ABCLiveRoomDelegate_h */

#import <Foundation/Foundation.h>
#import "ABCLiveUserMo.h"
#import "ABCPublicDefine.h"
#import "ABCMessageMo.h"

@protocol ABCLiveRoomDelegate <NSObject>
@optional
/**
 *  其他人上下麦信息（直播中用不到）
 *
 *  @param userId 用户id
 *  @param optUid 操作者id
 *  @param result 状态
 */
//-(void) onOtherMicStatus:(NSString *) userId optUid:(NSString *) optUid result:(ABCSpeakResult) result;
/**
 *  当前在线用户列表
 *
 *  @param userList 用户列表
 */
//-(void)    onRefreshUserList:(NSMutableArray *) userList;

/**
 *  用户进入房间
 *
 *  @param userMo ABCLiveUserMo
 */
-(void) onUserLogin:(ABCLiveUserMo *) userMo;

/**
 * 有用户信息的用户离开房间
 *
 *  @param userMo 用户model
 */
-(void) onUserLeaveHasUserInfo:(ABCLiveUserMo *) userMo;

/**
 * 用户离开房间
 *
 *  @param userIds 用户ids
 */
-(void) onUsersLeave:(NSArray *) userIds;

/**
 *  上下麦请求回调 （直播中用不到）
 *  @param userId 改变用户id
 *  @param result 状态
 *  @param optUid 授权人
 */

-(void) onResponseSpeak:(NSString *) userId optUid:(NSString *) optUid result:(ABCSpeakResult) result;;


-(void) onRemoteStreamStatusChange:(NSString *) uid roleType:(ABCRoleType) roleType streamType:(ABCStreamType) streamType status:(ABCStreamStatus) status;

-(void) onSelfStreamStatusChange:(ABCStreamType) streamType status:(ABCStreamStatus) status;


/**
 *  远端用户视频播放（直播中用不到）
 *
 *  @param uid    用户id
 *  @param isHost 是否为主播
 */
//-(void) onRemoteVideoJoin:(NSString *) uid isHost:(BOOL) isHost;

/**
 *  用户关闭视频（直播中用不到）
 *
 *  @param uid    用户id
 *  @param isHost 是否host
 */
//-(void) onVideoClose:(NSString *) uid isHost:(BOOL) isHost;

/**
 *  播放用户视频（直播中用不到）
 *
 *  @param uid 用户id
 */
//-(void) onVideoPlay:(NSString *) uid;

/**
 *  被禁言（直播中用不到）
 *
 *  @param isForbid 是否被禁言
 */
-(void) onForbidSpeakByTeacher:(BOOL) isForbid;

/**
 *  被禁止聊天 （直播中用不到）
 *
 *  @param isForbid 是否被禁止聊天
 */
-(void) onForbidChatByTeacher:(BOOL) isForbid;

/**
 *  邀请发言（直播中用不到）
 *
 *  @param fuid 被邀请人id
 */
-(void) onInviteSpeak:(NSString *) fuid;

/**
 *  同意邀请发言（直播中用不到）
 *
 *  @param userMo    用户信息
 *  @param isApprove 是否同意
 */
-(void) onApproveSpeak:(ABCLiveUserMo *) userMo isApprove:(BOOL) isApprove;

/**
 *  后台关闭直播间
 */
-(void) onCloseRoomByRemote;

/**
 *  用户被踢出
 */
-(void) onUserKickedOut:(NSString *) uid;

/**
 *  在线用户数发生改变
 */
-(void) onlineUserCount:(NSInteger) count;

#pragma mark - 答题卡
/**
 *  发起答题卡回复
 *  result 是否成功
 */
-(void) onSendQuestionCard:(BOOL)isSuccess;

/**
 *  收到老师发送的答题卡
 *
 */
-(void) onRecieveQuestionCard:(id)questionMo;

/**
 *  收到发送答案结果
 *
 */
- (void)onAnswerQuestion:(BOOL)isSuccess isCorrect:(BOOL)isCorrect answers:(NSString *)answers;

/**
 *  收到某同学答案结果
 *
 */
- (void)onRecieveAnswerQuestion:(id)statisticsMo;

/**
 *  请求答案结果
 *
 */
- (void)onGetAnswerQuestion:(id)statisticsMo;

/**
 *  停止答题
 *
 */
- (void)onSendStopQuestionCard:(BOOL)isSuccess;

/**
 *  收到停止答题
 *
 */
- (void)onRecieveStopQuestionCard;

#pragma mark - 共享白板
/**
 * 共享某个人的白板
 * uid为空表示停止共享
 */
-(void)onWhiteboardShare:(NSString *)shareWbId
               watchWBId:(NSString *)watchWBId;
/**
 * 切换白板
 */
-(void)onSwitchWBShare:(NSString *)whiteboardid;

@end

@protocol ABCLiveMsgDelegate <NSObject>
@optional
/**
 *  接收消息回调
 *
 *  @param messages ABCMessageMos
 */
-(void) onMessageRecive:(NSArray *) messages;
@end

@protocol ABCLiveStatusDelegate <NSObject>
@optional

/**
 *  用户状态
 *
 *  @param error ABCLiveErrorCode
 */
-(void) onError:(ABCLiveErrorCode) error;
/**
 *  登录成功
 */
-(void)	onLoginSucceed;
/**
 *  重连成功
 *
 *  @param type ABCConenctType
 */
-(void) onReconnected:(ABCConenctType) type;
/**
 *  重连中
 *
 *  @param type ABCConenctType
 */
-(void) onReconnecting:(ABCConenctType) type;


/**
 *  断开连接
 *
 *  @param type ABCConenctType
 */
-(void) onDisconnect:(ABCConenctType) type;


/**
 *  Host 当前状态
 *
 *  @param status CLOSE，IN，NOTIN，PUSH，NOTPUSH
 */
-(void) onHostStatusChange:(ABCHostStatus) status;

/**
 *  状态改变
 *
 *  @param status LiveStatusCode
 */
-(void) onStatusChange:(ABCStatusCode) status;


@end

@protocol ABCVideoStatusDelegate <NSObject>
@optional

/**
 *  视频播放状态
 *
 *  @param status ABCVideoStatus
 */
-(void) onVideoStatusChange:(ABCVideoStatus) status;

-(void) onVideoBuffferStateChange:(ABCVideoBufferStatus) status;

@end
