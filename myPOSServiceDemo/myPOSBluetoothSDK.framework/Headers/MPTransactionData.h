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

@end

NS_ASSUME_NONNULL_END
