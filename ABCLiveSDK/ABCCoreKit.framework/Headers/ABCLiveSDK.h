//
//  ABCLiveSDK.h
//  ABCLiveKit
//
//  Created by bing on 2017/5/16.
//  Copyright © 2017年 北京暄暄科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABCPublicDefine.h"
#import "ABCUserMo.h"

@class ABCRoomMo;

@interface ABCLiveSDK : NSObject

@property (nonatomic, strong ) NSString *appId;
@property (nonatomic, strong ) NSString *appSecret;

@property (nonatomic, assign ) BOOL     isLogin;
@property (nonatomic, assign ) BOOL     isDebug; //是否测试环境
@property (nonatomic, assign ) BOOL     isLocal; //是否局域网
@property (nonatomic, strong ) NSString *curUserId;

@property (nonatomic, strong ) ABCUserMo *curUserMo;


@property (nonatomic, strong ) NSString *userExt;

+ (instancetype)shareABCLiveSDK;

/**
 *  初始化ABCLiveSDK
 *
 *  @param token     token
 */
-(void) initWithToken:(NSString *) token;

/**
 *  扫码登录到网页云盘
 *
 *  @param verifyCode 验证code
 *  @param success    成功回调
 *  @param fail       失败回调
 */
-(void) loginByWebScan:(NSString *) verifyCode
               success:(void (^)(id responseObject))success
               failure:(void (^)(int errorCode,NSString *strMsg))fail;

/**
 *  创建新的课程（房间）
 *
 *  @param title 课程名称
 *  @param liveType     房间类型 0 互动 1 直播
 *  @param beginTime    非必填，房间开始时间，毫秒时间戳，若传则beginTime、endTime、duration都需要传回调
 *  @param endTime      非必填，房间开始时间，毫秒时间戳
 *  @param duration     非必填，房间持续时间，单位分钟

 */
-(void) creatRoom:(NSString *) title
        liveType:(int) liveType
        beginTime:(long) beginTime
          endTime:(long) endTime
         duration:(NSInteger) duration
          success:(void (^)(id responseObject))success
          failure:(void (^)(int errorCode,NSString *strMsg))fail;

/**
 *  上传文件到ABC云盘（PDF，xls,doc,ppt）
 *
 *  @param fileName  文件名称
 *  @param fileData  文件data数据
 *  @param success   成功回调
 *  @param fail      失败回调
 *  @param progress  上传进度
 */
-(void) uploadFileToABCCloud:(NSString *) fileName
                    fileSize:(long long)fileSize
                    fileData:(NSData *) fileData
                     success:(void (^)(id responseObject))success
                     failure:(void (^)(NSString *strMsg))fail
                    progress:(void (^)(float))progress;

/**
 *  获取云盘文件列表
 *
 *  @param success 成功回调
 *  @param fail    失败回调
 */
-(void) yunpanGetFileList:(NSInteger) page
                 pageSize:(NSInteger) pageSize
                  success:(void (^)(id responseObject))success
                  failure:(void (^)(NSString *strMsg))fail;

/**
 *  删除云盘文件
 *
 *  @param success 成功回调
 *  @param fail    失败回调
 */
-(void) yunpanDeleteById:(NSInteger)fid
                 success:(void (^)(id responseObject))success
                 failure:(void (^)(NSString *strMsg))fail;

/**
 *  下载云盘文件
 *
 *  @param fileUrl  文件url地址
 *  @param fileName 文件名称
 *  @param success  成功回调
 *  @param fail     失败回调
 */
-(void) yunpanDownloadFile:(NSString *) fileUrl
                      name:(NSString *) fileName
                   success:(void (^)(id responseObject))success
                   failure:(void (^)(NSString *strMsg))fail;

/**
 *  pdf文件上传
 *
 *  @param fileName  文件名称
 *  @param imageData 文件data
 *  @param success   成功回调
 *  @param fail      失败回调
 *  @param progress  上传进度
 */
-(void) yunpanUploadFile:(NSString *) fileName
                fileSize:(long long)fileSize
               imageData:(NSData *) imageData
                 success:(void (^)(id responseObject))success
                 failure:(void (^)(NSString *strMsg))fail
                progress:(void (^)(float progress))progress;

/**
 *  上传图片
 *
 *  @param imageName  图片名字
 *  @param imageData 图片data
 *  @param success   成功回调
 *  @param fail      失败回调
 *  @param progress  上传进度
 */
-(void) yunpanUploadImage:(NSString *) imageName
                imageData:(NSData *) imageData
                  success:(void (^)(id responseObject))success
                  failure:(void (^)(NSString *strMsg))fail
                 progress:(void (^)(float))progress;

-(void) getWbRecordResourceByRoomId:(NSString *) roomId
                            success:(void (^)(id responseObject))success
                            failure:(void (^)(int errorCode,NSString *strMsg))fail;

-(void) getOnlineUsers:(NSString *) roomId
                pageNo:(NSInteger) pageNo
              pageSize:(NSInteger) pageSize
               success:(void (^)(id responseObject))success
               failure:(void (^)(int errorCode,NSString *strMsg))fail;

@end
