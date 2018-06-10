//
//  ABCViewCrtlDelegate.h
//  ABCUIKit
//
//  Created by bingo on 2017/11/28.
//  Copyright © 2017年 北京暄暄科技有限公司. All rights reserved.
//

#ifndef ABCViewCrtlDelegate_h
#define ABCViewCrtlDelegate_h


#endif /* ABCViewCrtlDelegate_h */

@protocol ABCViewCrtlDelegate <NSObject>

@optional

- (void)onABCViewCtrlWillDismiss;

- (void)shareByShareType:(NSInteger)type
                  roomMo:(id)roomMo;


@end

