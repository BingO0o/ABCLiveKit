//
//  ABCQuestionCardMo.h
//  ABCCoreKit
//
//  Created by dev001 on 2017/10/23.
//  Copyright © 2017年 北京暄暄科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ABCQuestionMo : NSObject

@property (nonatomic, assign) NSInteger seq;
@property (nonatomic, assign) ABCQuestionType type;
@property (nonatomic, assign) NSInteger selectcount;
@property (nonatomic, strong) NSString *answers;

@end


@interface ABCAnswerDetailMo : NSObject

@property (nonatomic, strong) NSString *username;
@property (nonatomic, strong) NSString *answers;
@property (nonatomic, assign) long long timecost;

@end

@interface ABCStatisticsMo : NSObject

@property (nonatomic, assign) ABCQuestionType type;
@property (nonatomic, assign) NSInteger optionCount;
@property (nonatomic, strong) NSString *answers;

@property (nonatomic, assign) NSInteger answeredcount;
@property (nonatomic, assign) NSInteger totalcount;
@property (nonatomic, assign) NSInteger correctcount;
@property (nonatomic, assign) NSInteger counta;
@property (nonatomic, assign) NSInteger countb;
@property (nonatomic, assign) NSInteger countc;
@property (nonatomic, assign) NSInteger countd;
@property (nonatomic, assign) NSInteger counte;
@property (nonatomic, assign) NSInteger countf;
@property (nonatomic, strong) NSArray *details;

@end
