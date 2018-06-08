//
//  ABCCloudFileMo.h
//  ABCCoreKit
//
//  Created by bing on 2017/8/14.
//  Copyright © 2017年 北京暄暄科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ABCCloudFileMo : NSObject

@property(nonatomic,assign) NSInteger id;
@property(nonatomic,strong) NSString *fileName;
@property(nonatomic,strong) NSString *size;
@property(nonatomic,strong) NSString *lastModifyTime;
@property(nonatomic,strong) NSString *url;
@property(nonatomic,strong) NSString *shareUrl;

@end
