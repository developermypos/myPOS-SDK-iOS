//
//  MPCheckoutRequest.h
//  myPOSBluetoothSDK
//
//  Copyright © 2017 Intercard Finance AD. All rights reserved.
//

#import "MPRequest.h"

@interface MPCheckoutRequest : MPRequest

/*!
 *  @method referenceType
 *
 *  @return referenceType Returns the custom reference type set by the user to keep track of the transactions.
 *
 *  @see setTransactionReference:withType:
 */
- (MPReferenceType)referenceType;

/*!
 *  @method setTransactionReference:withType:
 *
 *  @param reference    Custom transaction reference can be set by the user to keep track of the transactions.
 *                      Must not exceed 50 characters.
 *  @param type         The type of the transaction reference.
 */
- (void)setTransactionReference:(nullable NSString *)reference withType:(MPReferenceType)type;

@end
