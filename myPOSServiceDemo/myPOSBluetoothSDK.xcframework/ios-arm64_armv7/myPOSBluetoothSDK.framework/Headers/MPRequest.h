//
//  MPRequest.h
//  myPOSBluetoothSDK
//
//  Copyright © 2017 Intercard Finance AD. All rights reserved.
//

#import "myPOSService.h"

@interface MPRequest : NSObject

@property (nonatomic, readonly) MPCurrency currency;
@property (nonnull, nonatomic, strong, readonly) NSDecimalNumber *total;
@property (nullable, nonatomic, strong, readonly) NSString *title;
@property (nullable, nonatomic, strong, readonly) NSString *receiptReceiver;

/*!
 *  @method requestWithTotal:title:currency:
 *
 *  @param  total       The amount to be charged
 *  @param  title       The name of the purchased product(s)
 *  @param  currency    The currency in which to charge the client
 */
+ (nonnull instancetype)requestWithTotal:(nonnull NSDecimalNumber *)total
                                   title:(nullable NSString *)title
                                currency:(MPCurrency)currency;

/*!
 *  @method requestWithTotal:title:currency:receiptReceiver:
 *
 *  @param  total           The amount to be charged
 *  @param  title           The name of the purchased product(s)
 *  @param  currency        The currency in which to charge the client
 *  @param  receiptReceiver A Phone or E-mail address to which a receipt
                            will be send after a successfull cehckout
 */
+ (nonnull instancetype)requestWithTotal:(nonnull NSDecimalNumber *)total
                                   title:(nullable NSString *)title
                                currency:(MPCurrency)currency
                         receiptReceiver:(nullable NSString *)receiptReceiver;

/*!
 *  @method reference
 *
 *  @return reference Returns a custom transaction reference set by the user to keep track of the transactions.
 *
 *  @see setTransactionReference:
 */
- (nullable NSString *)reference;

/*!
 *  @method setTransactionReference:
 *
 *  @param reference    Custom transaction reference can be set by the user to keep track of the transactions.
 *                      Must not exceed 20 characters.
 */
- (void)setTransactionReference:(nullable NSString *)reference;

@end
