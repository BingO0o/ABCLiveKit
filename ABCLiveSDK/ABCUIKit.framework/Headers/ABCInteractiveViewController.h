//
//  ABCInteractiveViewController.h
//  ABCLiveKit
//
//  Created by bing on 2017/6/14.
//  Copyright © 2017年 北京暄暄科技有限公司. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ABCViewCrtlDelegate.h"

@interface ABCInteractiveViewController : UIViewController

@property(nonatomic, weak) id<ABCViewCrtlDelegate> delegate;

-(instancetype) initABCInteractiveViewCtrlWithRoomMo:(ABCRoomMo *) roomMo;

@end
