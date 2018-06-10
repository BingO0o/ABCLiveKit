//
//  BlueDevSelectView.h
//  AlphaGo
//
//  Created by wangchun on 2016/10/24.
//  Copyright © 2016年 北京暄暄网络技术有限公司. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol BlueDevSelectViewDelegate <NSObject>

@optional
- (void)selectBlueDev:(NSInteger)index;

@end

@interface BlueDevSelectView : UIView

@property (nonatomic, strong) NSArray *arrSource;
@property (nonatomic, weak) id<BlueDevSelectViewDelegate> blueDevSelectViewDelegate;

@end
