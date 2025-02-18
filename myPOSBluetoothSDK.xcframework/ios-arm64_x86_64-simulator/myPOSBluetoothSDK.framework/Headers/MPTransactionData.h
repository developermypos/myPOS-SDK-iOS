//
//  MPTransactionData.h
//  myPOSBluetoothSDK
//
//  Created by Valio Cholakov on 18.03.20.
//  Copyright © 2020 myPOS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPTransactionData : NSObject

- (instancetype)initWithData:(id)data;

@property (nullable, nonatomic, strong) NSString *terminalId;
@property (nullable, nonatomic, strong) NSString *merchantId;
@property (nullable, nonatomic, strong) NSString *merchantName;
@property (nullable, nonatomic, strong) NSString *cardTypeId;
@property (nullable, nonatomic, strong) NSString *cardTypeName;
@property (nullable, nonatomic, strong) NSString *cardNumber;
@property (nullable, nonatomic, strong) NSString *localDate;
@property (nullable, nonatomic, strong) NSString *stan;
@property (nullable, nonatomic, strong) NSString *rrn;
@property (nullable, nonatomic, strong) NSString *reference;
@property (nullable, nonatomic, strong) NSString *approval;
@property (nullable, nonatomic, strong) NSString *embossName;
@property (nullable, nonatomic, strong) NSString *signatureNotRequired;
@property (nullable, nonatomic, strong) NSString *lastTransactionType;
@property (nullable, nonatomic, strong) NSString *merchantAl1;
@property (nullable, nonatomic, strong) NSString *merchantAl2;
@property (nullable, nonatomic, strong) NSString *authCode;
@property (nullable, nonatomic, strong) NSString *applicationPrefName;
@property (nullable, nonatomic, strong) NSString *cvm;
@property (nullable, nonatomic, strong) NSString *cardEntryMode;
@property (nullable, nonatomic, strong) NSString *balanceAmount;
@property (nullable, nonatomic, strong) NSString *balanceCurrency;
@property (nullable, nonatomic, strong) NSString *tipAmount;
@property (nullable, nonatomic, strong) NSString *declinedReason1;
@property (nullable, nonatomic, strong) NSString *declinedReason2;
@property (nullable, nonatomic, strong) NSString *expireDate;
@property (nullable, nonatomic, strong) NSString *оperatorCode;
@property (nullable, nonatomic, strong) NSString *logoType;
@property (nullable, nonatomic, strong) NSString *logoGuid;
@property (nullable, nonatomic, strong) NSString *customReceiptRow1;
@property (nullable, nonatomic, strong) NSString *customReceiptRow2;
@property (nullable, nonatomic, strong) NSString *terminalName;
@property (nullable, nonatomic, strong) NSString *configLogo;
@property (nullable, nonatomic, strong) NSString *dccCurrencyCode;
@property (nullable, nonatomic, strong) NSString *dccAmount;
@property (nullable, nonatomic, strong) NSString *dccCardExchangeRate;
@property (nullable, nonatomic, strong) NSString *referenceNumber;
@property (nullable, nonatomic, strong) NSString *referenceType;

@end

NS_ASSUME_NONNULL_END
