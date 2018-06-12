#  ABCLiveKit开发手册V1.0.3（ios）
[![Version](https://img.shields.io/cocoapods/v/ABCLive.svg?style=flat)](http://cocoapods.org/pods/ABCLive)
[![License](https://img.shields.io/cocoapods/l/ABCLive.svg?style=flat)](http://cocoapods.org/pods/ABCLive)
[![Platform](https://img.shields.io/cocoapods/p/ABCIM.svg?style=flat)](http://cocoapods.org/pods/ABCLive)

[TOC]

## REVISION HISTORY
Version | Date |Changed By |Changes
------|------|------|------
1.0.3 | 2018-06-11|Bing|2.0.0


## 环境准备
### 请确保满足以下开发环境要求：
* Apple XCode 6.0或以上版本
* iOS 9.0或以上版本
* 本sdk提供四个framework：
```  
1、ABCCoreKit.framework
2、ABCUIKit.framework
2、PenKit.framework
3、SocketIO.framework

添加ABCIMLib,ABCIMKit
添加ABCIMLib，ABCIMKit（使用Embedded Binaries 导入）
```
### pod导入
~~~
pod 'ABCLive/ABCLiveCoreKit', '~>1.0.3'
pod 'ABCLive/ABCLiveUIKit', '~>1.0.3'
pod 'ABCLive/ABCLivePenKit', '~>1.0.3'

由于SocketIO.framework 是swift库，请使用Embedded Binaries 导入，并在TARGETS->Build Settings ->Always Embed Swift Standard Libraries 设置为YES
~~~
## 快速接入直播互动
### Step1 初始化SDK
token生成规则详见服务器文档（*建议把appid和appsecret放到服务器操作）
~~~
[[ABCLiveSDK shareABCLiveSDK] initWithToken:token];
[ABCLiveSDK shareABCLiveSDK].curUserMo = [ABCUserMo new];//设置用户id,用户nickname,用户avataUrl。用户id必须跟申请token的id一致
~~~
### Step2 启动直播&互动页面
~~~
ABCInteractiveViewController *viewCtrl = [[ABCInteractiveViewController alloc] initABCInteractiveViewCtrlWithRoomMo:roomMo];
        [self presentViewController:viewCtrl animated:YES completion:nil];
~~~
~~~
ABCLivingViewController *viewCtrl = [[ABCLivingViewController alloc] initABCLivingViewCtrlWithRoomMo:roomMo];
        [self presentViewController:viewCtrl animated:YES completion:nil];
~~~
