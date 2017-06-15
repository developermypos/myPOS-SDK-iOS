//
//  Utils.h
//  myPOSServiceDemo
//
//  Copyright © 2017 Intercard Finance AD. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Utils : NSObject

+ (MPCurrency)savedCurrency;
+ (NSString *)currencyToString:(MPCurrency)currency;
+ (void)saveCurrency:(MPCurrency)currency;

@end
