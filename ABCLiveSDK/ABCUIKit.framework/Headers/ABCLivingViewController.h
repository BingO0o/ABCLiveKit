//
//  ABCLivingViewController.h
//  ABCLiveKit
//
//  Created by bing on 2017/5/25.
//  Copyright © 2017年 北京暄暄科技有限公司. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ABCViewCrtlDelegate.h"

@interface ABCLivingViewController : UIViewController

@property(nonatomic, weak) id<ABCViewCrtlDelegate> delegate;

@property(nonatomic, strong) UIImage *mutedVideoImage;

-(instancetype) initABCLivingViewCtrlWithRoomMo:(ABCRoomMo *) roomMo;

@end
