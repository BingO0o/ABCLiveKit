//
//  ABCChatWBViewController.h
//  ABCUIKit
//
//  Created by bing on 2017/9/5.
//  Copyright © 2017年 北京暄暄科技有限公司. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol ABCChatWBViewControllerDelegate <NSObject>

- (void)sendVideo:(NSURL *)url andImage:(UIImage *)image duration:(long) duration;

- (void)exitPageView;

@end

@interface ABCChatWBViewController : UIViewController


@property (nonatomic, weak) id<ABCChatWBViewControllerDelegate> delegate;

- (void)clickleftButton:(UIButton *)sender;



@end
