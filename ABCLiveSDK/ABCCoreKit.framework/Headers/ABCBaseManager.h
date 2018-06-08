//
//  ABCBaseManager.h
//  ABCCoreKit
//
//  Created by bing on 2017/9/5.
//  Copyright © 2017年 北京暄暄科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABCLiveRoomDelegate.h"

@interface ABCBaseManager : NSObject

@property (nonatomic, assign) BOOL isHost;

@property (nonatomic, strong) NSString *shareWhiteBoardId;
@property (nonatomic, strong ) NSString *watchWhiteboardId;//当前主白板中显示的白板id

@property (weak, nonatomic) id<ABCLiveRoomDelegate> roomDelegate;
@property (weak, nonatomic) id<ABCLiveMsgDelegate> msgDelegate;
@property (weak, nonatomic) id<ABCLiveStatusDelegate> statusDelegate;
@property (weak, nonatomic) id<ABCVideoStatusDelegate> videoStatusDelegate;

-(void) addWBDelegateWithWhiteBoardId:(NSString *) whiteBoardId wbDelegate:(id) wbDelegate;

-(id) getWBDelegateWithWhiteBoardId:(NSString *) whiteBoardId;

-(void) managerRelease;
/**
 * 发送白板cmd
 *
 * @param cmdData command data
 */
-(void) sendWhiteboardCmd:(NSData*) cmdData pageIndex:(int) pageIndex isReset:(BOOL)isReset isTxi:(BOOL)isTxi whiteboardId:(NSString *) whiteboardId;

/**
 * 获取白板历史数据
 */
-(NSMutableArray *) getHistoryWhiteboardCmdsByPageIndex:(int) pageIndex whiteBoardId:(NSString *) whiteBoardId;
/**
 * 同步白板某页历史数据
 */
-(void) sendGetWBMultiSyncByPageIndex:(int) pageIndex whiteBoardId:(NSString *) whiteBoardId;

@end
