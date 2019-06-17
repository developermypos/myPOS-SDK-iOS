//
//  TableViewController.m
//  myPOSServiceDemo
//
//  Copyright © 2017 Intercard Finance AD. All rights reserved.
//

#import <myPOSBluetoothSDK/myPOSBluetoothSDK.h>

#import "TableViewController.h"
#import "Utils.h"
#import "UIAlertController+Helpers.h"

typedef enum : NSInteger {
    TableViewSectionOperations, // 0
    TableViewSectionSettings,   // 1
} TableViewSection;

typedef enum : NSInteger {
    TableViewOperationRowPayment,      // 0
    TableViewOperationRowQuickPayment, // 1
    TableViewOperationRowRefund,       // 2
    TableViewOperationRowQuickRefund,  // 3
    TableViewOperationRowReprint,      // 4
    TableViewOperationRowActivate,     // 5
    TableViewOperationRowUpdate,       // 6
    TableViewOperationRowDeactivate,   // 7
} TableViewOperationRow;

typedef enum : NSInteger {
    TableViewSettingRowCurrency,        // 0
    TableViewSettingRowPrintReceipt,    // 1
} TableViewSettingRow;

@interface TableViewController () {
    MPCurrency _currency;
}

@end

@implementation TableViewController

static CGFloat const kFooterHeight = 30.0f;

#pragma mark - Controller Methods

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.tableView.tableFooterView = [UIView new];
    
    _currency               = [Utils savedCurrency];
    self.currencyLabel.text = [Utils currencyToString:_currency];
}

#pragma mark - Table View Delegate

- (CGFloat)tableView:(UITableView *)tableView heightForFooterInSection:(NSInteger)section {
    return section == TableViewSectionSettings ? kFooterHeight : 0.0f;
}

- (UIView *)tableView:(UITableView *)tableView viewForFooterInSection:(NSInteger)section {
    UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(0.0,
                                                               0.0,
                                                               tableView.bounds.size.width,
                                                               [self tableView:tableView heightForFooterInSection:section])];
    label.textAlignment = NSTextAlignmentCenter;
    label.text          = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"];
    
    return label;
}

- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    TableViewSection section = (TableViewSection)indexPath.section;
    
    switch (section) {
        case TableViewSectionOperations:
            switch ((TableViewOperationRow)indexPath.row) {
                case TableViewOperationRowPayment:
                    [self makePurchase];
                    break;
                    
                case TableViewOperationRowQuickPayment:
                    [self makeQuickPurchase];
                    break;
                    
                case TableViewOperationRowRefund:
                    [self makeRefund];
                    break;
                    
                case TableViewOperationRowQuickRefund:
                    [self makeQuickRefund];
                    break;
                    
                case TableViewOperationRowReprint:
                    [self reprintLastReceipt];
                    break;
                    
                case TableViewOperationRowActivate:
                    [self activate];
                    break;
                    
                case TableViewOperationRowUpdate:
                    [self update];
                    break;
                    
                case TableViewOperationRowDeactivate:
                    [self deactivate];
                    break;
            }
            break;
            
        case TableViewSectionSettings:
            switch ((TableViewSettingRow)indexPath.row) {
                case TableViewSettingRowCurrency:
                    [self changeCurrency];
                    break;
                    
                case TableViewSettingRowPrintReceipt:
                    [self changePrintReceipt];
                    break;
            }
            break;
    }
    
    
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
}

#pragma mark - Private Methods

- (void)makePurchase {
    MPCheckoutRequest *checkoutRequest = [MPCheckoutRequest requestWithTotal:[NSDecimalNumber decimalNumberWithString:@"1.00"]
                                                                       title:@"Some item"
                                                                    currency:_currency];
    
    [checkoutRequest setTransactionReference:@"my_transaction_reference" withType:MPReferenceTypeNumber];
    NSLog(@"Request: %@", checkoutRequest);
    [myPOSService checkoutWithRequest:checkoutRequest fromViewController:self completion:[self completion:@"Payment"]];
}

- (void)makeQuickPurchase {
    MPCheckoutRequest *checkoutRequest = [MPCheckoutRequest requestWithTotal:[NSDecimalNumber decimalNumberWithString:@"1.00"]
                                                                       title:@"Some item"
                                                                    currency:_currency];
    
    [checkoutRequest setTransactionReference:@"my_transaction_reference" withType:MPReferenceTypeNumber];
    NSLog(@"Request: %@", checkoutRequest);
    [myPOSService quickCheckoutWithRequest:checkoutRequest fromViewController:self completion:[self completion:@"Payment"]];
}

- (void)makeRefund {
    MPRefundRequest *refundRequest = [MPRefundRequest requestWithTotal:[NSDecimalNumber decimalNumberWithString:@"1.00"]
                                                                 title:@"Some item"
                                                              currency:_currency];
    NSLog(@"Request: %@", refundRequest);
    [myPOSService requestRefund:refundRequest fromViewController:self completion:[self completion:@"Refund"]];
}

- (void)makeQuickRefund {
    MPRefundRequest *refundRequest = [MPRefundRequest requestWithTotal:[NSDecimalNumber decimalNumberWithString:@"1.00"]
                                                                 title:@"Some item"
                                                              currency:_currency];
    NSLog(@"Request: %@", refundRequest);
    [myPOSService requestQuickRefund:refundRequest fromViewController:self completion:[self completion:@"Refund"]];
}

- (void)update {
    [myPOSService requestUpdateTerminalFromController:self withCompletion:[self completion:@"Update"]];
}

- (void)activate {
    [myPOSService requestActivateTerminalFromController:self withCompletion:[self completion:@"Activation"]];
}

- (void)deactivate {
    [myPOSService requestDeactivateTerminalFromController:self withCompletion:[self completion:@"Deactivateion"]];
}

- (void)reprintLastReceipt {
    [myPOSService reprintLastReceiptWithCompletion:[self completion:@"Reprint last receipt"]];
}

- (void)changeCurrency {
    [UIAlertController showCurrencyPickerFromController:self selectionHandler:^(MPCurrency currency) {
        _currency               = currency;
        self.currencyLabel.text = [Utils currencyToString:currency];
        
        [Utils saveCurrency:currency];
    }];
}

- (void)changePrintReceipt {
    [UIAlertController showReceiptOptionsFromController:self selectionHandler:^(MPDeviceReceipt receiptType, NSString *actionTitle) {
        [myPOSService setReceiptType:receiptType];
        [self.receiptTypeLabel setText:actionTitle];
    }];
}

#pragma mark - Helpers

- (MPRequestCompletion)completion:(NSString *)operation {
    return ^(NSError *error) {
        [UIAlertController showAlertWithTitle:error ? @"An error occured"        : @"Operation completed"
                                      message:error ? error.localizedDescription : [NSString stringWithFormat:@"%@ completed successfully", operation]
                               fromController:self];
        
        if (error.code == -1) {
            [self.navigationController popViewControllerAnimated:YES];
        }
    };
}

@end
