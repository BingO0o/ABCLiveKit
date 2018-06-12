//
//  ViewController.m
//  ABCLiveDemo
//
//  Created by bingo on 2018/6/11.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import "ViewController.h"
#import <ABCUIKit/ABCUIKit.h>
#import <AFNetworking.h>
#include <CommonCrypto/CommonCrypto.h>

#import "MainViewController.h"

#define ABC_LIVE_APP_ID     @""
#define ABC_LIVE_APP_SECRET @""
#define AUTH_DOMAIN         @"https://open.abcpen.com"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (IBAction)getABCToken:(id)sender {
    if (_textUserId.text.length ==0 || _textNickName.text.length == 0) {
        return;
    }
    
    long long expireTime = 10000000000;
    long nonce = 123456;//1000000 +  (arc4random() % 1000000);
    NSString *sign = [self getABCSign:ABC_LIVE_APP_ID appSecret:ABC_LIVE_APP_SECRET uid:_textUserId.text expireTime:expireTime nonceStr:nonce];
    
    NSMutableDictionary *param = [NSMutableDictionary dictionaryWithDictionary:@{}];
    [param addEntriesFromDictionary:@{@"appId":ABC_LIVE_APP_ID,@"expireTime":@(expireTime),@"uid":_textUserId.text,@"nonceStr":[NSString stringWithFormat:@"%ld",nonce],@"sign":sign,@"nickName":_textNickName.text,@"avatarUrl":@"111",@"type":@"1"}];
    
    NSURLSessionConfiguration *config = [NSURLSessionConfiguration defaultSessionConfiguration];
    AFHTTPSessionManager *manager = [[AFHTTPSessionManager alloc] initWithSessionConfiguration:config];
    manager.responseSerializer = [AFJSONResponseSerializer serializer];
    manager.responseSerializer.acceptableContentTypes = [NSSet setWithObjects:@"application/json",
                                                         nil];
    [manager POST:[NSString stringWithFormat:@"%@/api/user/getToken",AUTH_DOMAIN] parameters:param progress:^(NSProgress * _Nonnull uploadProgress) {
    } success:^(NSURLSessionDataTask * _Nonnull task, id  _Nullable responseObject) {
        if ([[responseObject objectForKey:@"success"] boolValue]) {
            ABCUserMo *userMo = [[ABCUserMo alloc] init];
            userMo.userId = self.textUserId.text;
            userMo.nickName = self.textNickName.text;
            [[ABCLiveSDK shareABCLiveSDK] initWithToken:[responseObject objectForKey:@"data"]];
            [ABCLiveSDK shareABCLiveSDK].curUserMo = userMo;
            [self presentViewController:[MainViewController new] animated:YES completion:nil] ;
        }else{
            NSLog(@"%@", [responseObject objectForKey:@"errorMsg"]);
        }
    } failure:^(NSURLSessionDataTask * _Nullable task, NSError * _Nonnull error) {
    }];
}

-(NSString *) getABCSign:(NSString *) appid
               appSecret:(NSString *) appSecret
                     uid:(NSString *) uid
              expireTime:(long) expireTime
                nonceStr:(long) nonceStr
{
    NSString *signStr = [NSString stringWithFormat:@"appId=%@&expireTime=%ld&uid=%@&nonceStr=%ld",appid,expireTime,uid,nonceStr];
    signStr = [self md5String:[signStr dataUsingEncoding:NSUTF8StringEncoding]];
    signStr = [NSString stringWithFormat:@"%@&appSecret=%@",signStr,appSecret];
    signStr = [[self md5String:[signStr dataUsingEncoding:NSUTF8StringEncoding]] uppercaseString];
    return signStr;
}

- (NSString *)md5String:(NSData *) data
{
    unsigned char result[16];
    CC_MD5(data.bytes,(CC_LONG)data.length, result);
    return [NSString stringWithFormat:
            @"%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
            result[0], result[1], result[2], result[3],
            result[4], result[5], result[6], result[7],
            result[8], result[9], result[10], result[11],
            result[12], result[13], result[14], result[15]
            ];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


@end
