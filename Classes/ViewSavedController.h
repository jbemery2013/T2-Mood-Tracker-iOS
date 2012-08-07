//
//  ViewSavedController.h
//  VAS002
//
//  Created by Melvin Manzano on 3/28/12.
//  Copyright (c) 2012 GDIT. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MessageUI/MessageUI.h>
#import <MessageUI/MFMailComposeViewController.h>
#import <ShinobiCharts/ShinobiChart.h>
#import "ShinobiCharts/SChartGLView+Screenshot.h"
#import "ShinobiCharts/ShinobiChart+Screenshot.h"
#import "ChartPrintDataSource.h"
#import <dispatch/dispatch.h>
#import "PDFService.h"


#define kBorderInset            20.0
#define kBorderWidth            1.0
#define kMarginInset            10.0

//Line drawing
#define kLineWidth              1.0


@class Saved;
@class MailData;

@interface ViewSavedController : UIViewController <UIWebViewDelegate, UIActionSheetDelegate, MFMailComposeViewControllerDelegate, SChartDelegate, PDFServiceDelegate>
{
    ShinobiChart            *chart;
    ChartPrintDataSource         *datasource;    
    dispatch_queue_t backgroundQueue;
    Saved *saved;
    IBOutlet UIWebView *printContentWebView;
    NSString *pdfPath;
    IBOutlet UIActivityIndicatorView *activityInd;
    NSString *finalPath;
    NSString *fileName;
    NSString *fileType;

}

@property (nonatomic, retain) Saved *saved;
@property (nonatomic, retain) UIWebView *printContentWebView;
@property (nonatomic, retain) NSString *pdfPath;
@property (nonatomic, retain) IBOutlet UIActivityIndicatorView *activityInd;
@property (nonatomic, retain) NSString *finalPath;
@property (nonatomic, retain) NSString *fileName;
@property (nonatomic, retain) NSString *fileType;


- (void)sendMail:(MailData *)mailData;
- (void)displayComposerSheetWithMailData:(MailData *)data;
- (void)launchMailAppOnDeviceWithMailData:(MailData *)data;
- (void)mailComposeController:(MFMailComposeViewController*)controller didFinishWithResult:(MFMailComposeResult)result error:(NSError*)error;
- (void)emailResults;
- (void) finishSetup;
- (void) getScreenShot;
- (void) createPDFDocument;
- (void) createWebViewWithHTML;
- (NSMutableDictionary *) parseNotes:(NSString *)fileContents;
- (void) shareClick;
- (void) makePDF;
- (void) drawPDF:(UIImage *)reportImage;

- (void)drawPageNumber:(NSInteger)pageNum;

@end
