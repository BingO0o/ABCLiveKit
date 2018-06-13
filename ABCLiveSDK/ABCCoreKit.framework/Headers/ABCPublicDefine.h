//
//  ABCPublicDefine.h
//  ABCCoreKit
//
//  Created by bing on 2017/8/12.
//  Copyright © 2017年 北京暄暄科技有限公司. All rights reserved.
//

#ifndef ABCPublicDefine_h
#define ABCPublicDefine_h

typedef NS_ENUM(NSInteger, ABCRoleType) {
    ABCRoleType_STUDENT = 1,    // 学生
    ABCRoleType_TEACHER,        // 老师
    ABCRoleType_HIDER,          // 协调者，隐形人
    ABCRoleType_GUEST,          // 访客
    ABCRoleType_MANAGER         //管理者
};

typedef NS_ENUM(NSInteger, ABCSpeakResult)  {
    ABCSpeakResult_UP_REQ_OK = 1,       // 请求发送成功 等待上麦审核
    ABCSpeakResult_UP_OK,           // 上麦完成 设置下麦逻辑
    ABCSpeakResult_DOWN_SEND_OK,    // 下麦请求发送成功 等待下麦审核
    ABCSpeakResult_DOWN_OK,         // 下麦完成 设置上麦逻辑
    ABCSpeakResult_UP_REQ_FAIL,     // 上麦请求失败
    ABCSpeakResult_DOWN_REQ_FAIL,    // 下麦请求失败
    ABCSpeakResult_NEW_SHOW_HAND,   // 教师收到学生的举手 通知到UI要让其触发获取更新的用户列表
    ABCSpeakResult_UP_SUCCESS,
    ABCSpeakResult_OTHER_SHOW_HAND  //其他人请求上麦
    
    /** 备注: 之前描述是这样的 以下已经不用 废弃!
     * status 1 请求发送成功 等待上麦审核
     * status 2 上麦完成 设置下麦逻辑
     * status 3 下麦请求发送成功 等待下麦审核
     * status 4 下麦完成 设置上麦逻辑
     * status -1 上麦请求失败
     * status -2 下麦请求失败
     **/
};


/**
 *  CLOSE;IN;NOTIN;PUSH;NOTPUSH
 */
typedef NS_ENUM(NSInteger, ABCHostStatus) {
    ABCHost_COLOSE = 0,
    ABCHost_IN,
    ABCHost_NOTIN,
    ABCHost_PUSH,
    ABCHost_NOTPUSH
};


typedef NS_ENUM(NSInteger, ABCConenctType) {
    ABCConenctType_wb,
    ABCConenctType_video
};

typedef NS_ENUM(NSInteger ,ABCStatusCode){
    ABCStatusCode_BeginPublish,
    ABCStatusCode_FinishMeeting,
    ABCStatusCode_HostCloseVideo,
    ABCStatusCode_NoVideoStrem,
    ABCStatusCode_OnDownMic,
};

typedef NS_ENUM(NSInteger ,ABCLiveErrorCode){
    ABCLiveErrorCode_loginFail,
    ABCLiveErrorCode_loginOtherDevice,
    ABCLiveErrorCode_getLivingUrlFail,
    ABCLiveErrorCode_serverFail,
    ABCLiveErrorCode_tokenExpired
};

typedef NS_ENUM(NSInteger ,ABCVideoStatus){
    ABCVideoStatus_Ready = 0,
    ABCVideoStatus_Pending = 1,
    ABCVideoStatus_Start = 2,
    ABCVideoStatus_Stop = 3,
    ABCVideoStatus_Error = 4,
    ABCVideoStatus_Refresh = 5
};

typedef NS_ENUM(NSInteger, ABCStreamStatus) {
    ABCStreamStatus_OPEN,
    ABCStreamStatus_CLOSE
};

/**
 * StreamType 流 type 值
 1：音频
 2：视频
 3：音频+视频
 4：桌面
 5：音频+桌面
 6：视频+桌面
 7：音频+视频+桌面
 当前只使用  ABCStreamType_AUDIO ， ABCStreamType_VIDEO
 */

typedef NS_ENUM(NSInteger, ABCStreamType) {
    ABCStreamType_NO_DEFINE=-1,
    ABCStreamType_NONE=0,
    ABCStreamType_AUDIO=1,
    ABCStreamType_VIDEO=2,
    ABCStreamType_AUDIO_VIDEO=3,
    ABCStreamType_DESKTOP=4,
    ABCStreamType_AUDIO_DESKTOP=5,
    ABCStreamType_VIDEO_DESKTOP=6,
    ABCStreamType_AUDIO_VIDEO_DESKTOP=7,
    
};

typedef NS_ENUM(NSInteger ,ABCVideoBufferStatus){
    ABCVideoBufferStatus_Unknown = 0,   // 未知
    ABCVideoBufferStatus_Increase = 1,  // 缓冲区状态差应该降低码率
    ABCVideoBufferStatus_Decline = 2    // 缓冲区状态好应该提升码率
};

typedef NS_ENUM(NSInteger, ABCErrorCode) {
    ABCErrorCode_REQUEST_ERROR        = -10000, //请求失败
    ABCErrorCode_COOKIE_EXPIRED       = 10006, //TOKEN 过期
};

/// 视频分辨率(都是16：9 当此设备不支持当前分辨率，自动降低一级)
typedef NS_ENUM (NSUInteger, ABCVideoResolution){
    /// 低分辨率
    ABCVideoResolutionLow = 0,
    /// 中分辨率
    ABCVideoResolutionMid = 1,
    /// 高分辨率
    ABCVideoResolutionHigh = 2
};

typedef enum ABCQuestionType{
    ABCQuestionType_Single = 1, //单选
    ABCQuestionType_Multi, //多选
    ABCQuestionType_Whether, //是非
}ABCQuestionType;


//画笔功能类型
typedef enum ABCWBLineStyle{
    ABCWBLineStyle_Small = 0,                //细
    ABCWBLineStyle_Mid,                      //中
    ABCWBLineStyle_Large                     //粗
}ABCWBLineStyle;

//颜色选择
typedef enum ABCWBColorStyle{
    ABCWBColorStyle_000000=0,                //黑
    ABCWBColorStyle_EA1C24,                  //红
    ABCWBColorStyle_0071BC,                  //蓝
    ABCWBColorStyle_008F45,                  //绿
    ABCWBColorStyle_FFBC11                   //黄
}ABCWBColorStyle;

//RoomMo 中dicExtra
#define COURSEID        @"COURSEID"
#define STARTTIME       @"STARTTIME"

#define COMMOND_WHITE_BOARD_ID @"0" //公共白板id

#endif /* ABCPublicDefine_h */
