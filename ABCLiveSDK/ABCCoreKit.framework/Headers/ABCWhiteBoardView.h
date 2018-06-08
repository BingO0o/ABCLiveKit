//
//  ABCWhiteBoardView.h
//  ABCCoreKit
//
//  Created by bing on 2017/8/15.
//  Copyright © 2017年 北京暄暄科技有限公司. All rights reserved.
//

#import <UIKit/UIKit.h>

@class ABCBaseManager;


@protocol ABCWhiteBoardViewDelegate <NSObject>

@optional
/**
 *  重置白板结束，可在此回调中更新current page
 */
-(void) onResetWhiteBoardFinish;

-(void) pageControllerClick:(id) sender;//单击

- (void)currpageChange;

- (void)handleSwipeFrom:(UISwipeGestureRecognizer *)recognizer;

@end

@interface ABCWhiteBoardView : UIView

@property(nonatomic, weak) id<ABCWhiteBoardViewDelegate> delegate;

@property(nonatomic, assign) ABCWBLineStyle linStyle;//whiteboard line width

@property(nonatomic, assign) ABCWBColorStyle colorStyle;//whiteboard color

@property(nonatomic, assign) BOOL isEaser;//是否为橡皮檫

@property(nonatomic, assign) NSInteger currentPage;//current page

@property(nonatomic, assign) NSInteger totalPage;//total page

@property(nonatomic, strong) ABCBaseManager *livingManager;

@property(nonatomic, assign) CGSize paperSize;

@property(nonatomic, readonly) CGSize canvasSize;

@property(nonatomic, strong) NSString *wbId;//白板Id
@property(nonatomic, assign) BOOL isBroadcast;//是否广播

/**
 *  初始化WhiteBoardView
 *
 *  @param frame      frame 决定白板可绘制区域（1920*1080 等比例最佳）
 *  @param isPortrait 是否竖屏
 *  @param isLocal 本地录制，非互动
 *  @return ABCWhiteBoardView
 */
-(instancetype) initWhiteBoardView:(CGRect) frame isPortrait:(int) isPortrait isLocal:(BOOL) isLocal;

/**
 *  设置白板图片
 *
 *  @param imageUrl     图片url地址
 *  @param image        UIImage
 *  @param pageIndex    页码
 */
-(void) addWhiteBoardImage:(NSString *) imageUrl imageData:(UIImage *) image pageIndex:(NSInteger)pageIndex;

/**
 *  设置PDF文件
 *
 *  @param localPath 本地地址
 *  @param fileUrl   云盘地址
 */
-(bool)addPDFWithLocalPath:(NSString *) localPath fileUrl:(NSString *) fileUrl;

/**
 *  重置笔颜色线等类型
 *
 */
- (void)resetDefaultSetting;

/**
 *  移除羽毛笔等图片
 *
 */
- (void)removeLaserPoint;


/**
 *  更新可绘制区域
 *  当改变白板大小的时候一定要调用此方法
 *
 *  @param size CGSize
 */
-(void) updateWhiteBoardSize:(CGSize) size;

/**
 *  清除当前页
 */
-(void) clearPage;

/**
 *  重置白板
 */
-(void) resetWhiteBoard;

/**
 *  重置白板（pdf下载完成后重置不需要alert）
 */
-(void) resetWBWithoutAlert;

/**
 *  释放白板数据
 */
-(void) releaseWBView;

/**
 *  上一页
 *
 *  @return pageno
 */
-(NSInteger) previousPage;

/**
 *  下一页
 *
 *  @return pageno
 */
-(NSInteger) nextPage;

/**
 *  在最后追加一页
 *
 *  @return pageno
 */
-(NSInteger) additionalNewPage;

-(UIImage *) saveCurrentPageToImage;

//根据蓝牙板画点
- (void)drawCanvasByPoint:(CGPoint)point isRoute:(BOOL)isRoute pressure:(float)pressure;

- (void)drawCanvasByPoint:(CGPoint)point touchState:(int)touchState pressure:(float)pressure;

- (void)drawCanvasByPoint:(CGPoint)point position:(int)position pressure:(float)pressure;

@end
