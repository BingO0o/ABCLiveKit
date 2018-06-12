//
//  AppDelegate.m
//  ABCLiveDemo
//
//  Created by bingo on 2018/6/11.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import "AppDelegate.h"
#import <ABCCoreKit/ABCLiveSDK.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Override point for customization after application launch.
    [ABCLiveSDK shareABCLiveSDK].isDebug = YES;
    [ABCLiveSDK shareABCLiveSDK].isLocal = YES;
    [[ABCLiveSDK shareABCLiveSDK] initWithToken:@"eyJhbGciOiJIUzI1NiJ9.eyJsYXN0TG9naW5UaW1lIjoxNTI4NzAwNjQ3MTgyLCJvcGVuSWQiOiIxMDg1NzY5IiwiYXBwSWQiOiJwbEd2Zzc0Wkc4Mk12N1ZSb0RnVVlWUnlDd2Z4VzBrVCIsIm9wZW5JZFR5cGUiOiIxMSIsImlzcyI6IkFiY1BlbiIsImV4cCI6MTUzODcwMDY0NzE4MiwidXNlcklkIjo2MTgyNywiaWF0IjoxNTI4NzAwNjQ3MTgyLCJqdGkiOiIxLjAifQ.UIHfd2Z9gJPMzUFVvzMx60Gy6fF4MJbJ2s4FfmJm3KU"];
    return YES;
}


- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
