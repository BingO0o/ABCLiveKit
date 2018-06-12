//
//  MainViewController.m
//  ABCLiveDemo
//
//  Created by bingo on 2018/6/12.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import "MainViewController.h"
#import <ABCUIKit/ABCUIKit.h>

@interface MainViewController ()
@property (weak, nonatomic) IBOutlet UISwitch *switchLiveType;

@property (weak, nonatomic) IBOutlet UISwitch *switchUserRole;
@property (weak, nonatomic) IBOutlet UITextField *textRoomId;
@end

@implementation MainViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view from its nib.
}
- (IBAction)enterRoom:(id)sender {
    if(_textRoomId.text.length == 0){
        return;
    }
    ABCRoomMo *roomMo = [[ABCRoomMo alloc] init];
    roomMo.room_id = _textRoomId.text;
    roomMo.isHost = _switchUserRole.on;
    roomMo.abcPenType = 4;
    if(_switchLiveType.on){
        ABCInteractiveViewController *viewCtrl = [[ABCInteractiveViewController alloc] initABCInteractiveViewCtrlWithRoomMo:roomMo];
        [self presentViewController:viewCtrl animated:YES completion:nil] ;
    }else{
        ABCLivingViewController *viewCtrl = [[ABCLivingViewController alloc] initABCLivingViewCtrlWithRoomMo:roomMo];
        [self presentViewController:viewCtrl animated:YES completion:nil];
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
