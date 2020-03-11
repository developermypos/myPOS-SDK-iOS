//
//  UIAlertController+Helpers.m
//  myPOSServiceDemo
//
//  Copyright © 2017 Intercard Finance AD. All rights reserved.
//

#import <myPOSBluetoothSDK/myPOSBluetoothSDK.h>

#import "UIAlertController+Helpers.h"
#import "Utils.h"

@implementation UIAlertController (Helpers)

#pragma mark - Public Methods

+ (void)showAlertWithTitle:(NSString *)title message:(NSString *)message fromController:(UIViewController *)sender {
    UIAlertAction     *okAction        = [UIAlertAction actionWithTitle:NSLocalizedString(@"Ok", @"") style:UIAlertActionStyleCancel handler:nil];
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:title
                                                                             message:message
                                                                      preferredStyle:UIAlertControllerStyleAlert];
    [alertController addAction:okAction];
    [sender presentViewController:alertController animated:YES completion:nil];
}

+ (void)showCurrencyPickerFromController:(UITableViewController<UIPopoverPresentationControllerDelegate> *)sender
                        selectionHandler:(void(^)(MPCurrency currency))selectionHandler {
    
    UIAlertAction     *okAction        = [UIAlertAction actionWithTitle:NSLocalizedString(@"Cancel", @"") style:UIAlertActionStyleCancel handler:nil];
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:NSLocalizedString(@"Select currency", @"")
                                                                             message:nil
                                                                      preferredStyle:UIAlertControllerStyleActionSheet];
    [alertController addAction:okAction];
    
    [[self availableCurrencies] enumerateObjectsUsingBlock:^(NSNumber * _Nonnull currency, NSUInteger idx, BOOL * _Nonnull stop) {
        UIAlertAction *currencyAction = [UIAlertAction actionWithTitle:[Utils currencyToString:currency.integerValue] style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
            selectionHandler(currency.integerValue);
        }];
        [alertController addAction:currencyAction];
    }];
    
    if (alertController.popoverPresentationController) {
        alertController.popoverPresentationController.delegate   = sender;
        alertController.popoverPresentationController.sourceView = [sender tableView];
        alertController.popoverPresentationController.sourceRect = [[sender tableView] rectForRowAtIndexPath:[sender.tableView indexPathForSelectedRow]];
    }
    
    [sender presentViewController:alertController animated:YES completion:nil];
}

+ (void)showReceiptOptionsFromController:(UITableViewController<UIPopoverPresentationControllerDelegate> *)sender
                        selectionHandler:(void (^)(MPDeviceReceipt receiptType, NSString *actionTitle))selectionHandler {
    
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:NSLocalizedString(@"Select receipt print option", @"")
                                                                             message:nil
                                                                      preferredStyle:UIAlertControllerStyleActionSheet];
    
    UIAlertAction *cancel = [UIAlertAction actionWithTitle:NSLocalizedString(@"Cancel", @"") style:UIAlertActionStyleCancel handler:nil];
    
    UIAlertAction *automatically = [UIAlertAction actionWithTitle:@"Automatically" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        selectionHandler(MPDeviceReceiptPrintAutomatically, action.title);
    }];
    
    UIAlertAction *afterConfirmation = [UIAlertAction actionWithTitle:@"After confirmation" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        selectionHandler(MPDeviceReceiptPrintAfterConfirmation, action.title);
    }];
    
    UIAlertAction *onlyMerchantCopy = [UIAlertAction actionWithTitle:@"Only merchant copy" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        selectionHandler(MPDeviceReceiptPrintOnlyMerchantCopy, action.title);
    }];
    
    UIAlertAction *doNotPrint = [UIAlertAction actionWithTitle:@"Do not print" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        selectionHandler(MPDeviceReceiptDoNotPrint, action.title);
    }];
    
    [alertController addAction:cancel];
    [alertController addAction:automatically];
    [alertController addAction:afterConfirmation];
    [alertController addAction:onlyMerchantCopy];
    [alertController addAction:doNotPrint];
    
    if (alertController.popoverPresentationController) {
        alertController.popoverPresentationController.delegate   = sender;
        alertController.popoverPresentationController.sourceView = [sender tableView];
        alertController.popoverPresentationController.sourceRect = [[sender tableView] rectForRowAtIndexPath:[sender.tableView indexPathForSelectedRow]];
    }
    
    [sender presentViewController:alertController animated:YES completion:nil];
}

#pragma mark - Helpers

+ (NSArray<NSNumber *> *)availableCurrencies {
    return @[
             @(MPCurrencyUSD),
             @(MPCurrencySEK),
             @(MPCurrencyRON),
             @(MPCurrencyPLN),
             @(MPCurrencyNOK),
             @(MPCurrencyISK),
             @(MPCurrencyHUF),
             @(MPCurrencyBGN),
             @(MPCurrencyCHF),
             @(MPCurrencyCZK),
             @(MPCurrencyDKK),
             @(MPCurrencyEUR),
             @(MPCurrencyGBP),
             @(MPCurrencyHRK)
             ];
}

@end
