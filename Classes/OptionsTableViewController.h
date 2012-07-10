//
//  OptionsTableViewController.h
//  VAS002
//
//  Created by Melvin Manzano on 7/9/12.
//  Copyright (c) 2012 GDIT. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>
#import "SafeFetchedResultsController.h"


@interface OptionsTableViewController : UITableViewController <UINavigationControllerDelegate, SafeFetchedResultsControllerDelegate>
{
    SafeFetchedResultsController *fetchedResultsController;
    NSManagedObjectContext *managedObjectContext;
    NSArray *dataSourceArray;
    UINavigationController *myNavController;

    UISwitch *legendSwitch;
    UISwitch *symbolSwitch;
    UISwitch *gradientSwitch;
}

@property (nonatomic, retain) SafeFetchedResultsController *fetchedResultsController;
@property (nonatomic, retain) NSManagedObjectContext *managedObjectContext;
@property (nonatomic, retain) NSArray *dataSourceArray;
@property (nonatomic, retain) UINavigationController *myNavController;
@property (nonatomic, retain) UISwitch *legendSwitch;
@property (nonatomic, retain) UISwitch *symbolSwitch;
@property (nonatomic, retain) UISwitch *gradientSwitch;


- (void)legendToggle;
- (void)symbolToggle;
- (void)gradientToggle;

@end