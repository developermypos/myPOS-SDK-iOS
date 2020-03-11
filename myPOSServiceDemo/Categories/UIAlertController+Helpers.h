//
//  UIAlertController+Helpers.h
//  myPOSServiceDemo
//
//  Copyright © 2017 Intercard Finance AD. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIAlertController (Helpers)

+ (void)showAlertWithTitle:(NSString *)title message:(NSString *)message fromController:(UIViewController *)sender;

+ (void)showCurrencyPickerFromController:(UITableViewController<UIPopoverPresentationControllerDelegate> *)sender
                        selectionHandler:(void(^)(MPCurrency currency))selectionHandler;

+ (void)showReceiptOptionsFromController:(UITableViewController<UIPopoverPresentationControllerDelegate> *)sender
                        selectionHandler:(void (^)(MPDeviceReceipt receiptType, NSString *actionTitle))selectionHandler;

@end
