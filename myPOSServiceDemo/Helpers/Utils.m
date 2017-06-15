//
//  Utils.m
//  myPOSServiceDemo
//
//  Copyright © 2017 Intercard Finance AD. All rights reserved.
//

#import <myPOSBluetoothSDK/myPOSBluetoothSDK.h>

#import "Utils.h"

@implementation Utils

static NSString * const kCurrency = @"currency";

#pragma mark - Public Methods

+ (void)saveCurrency:(MPCurrency)currency {
    [[NSUserDefaults standardUserDefaults] setInteger:currency forKey:kCurrency];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

+ (MPCurrency)savedCurrency {
    MPCurrency currency = [[NSUserDefaults standardUserDefaults] integerForKey:kCurrency];
    
    return currency == MPCurrencyUnknown ? MPCurrencyEUR : currency;
}

+ (NSString *)currencyToString:(MPCurrency)currency {
    switch (currency) {
        case MPCurrencyBGN:
            return @"BGN";
            
        case MPCurrencyCHF:
            return @"CHF";
            
        case MPCurrencyCZK:
            return @"CZK";
            
        case MPCurrencyDKK:
            return @"DKK";
            
        case MPCurrencyEUR:
            return @"EUR";
            
        case MPCurrencyGBP:
            return @"GBP";
            
        case MPCurrencyHRK:
            return @"HRK";
            
        case MPCurrencyHUF:
            return @"HUF";
            
        case MPCurrencyISK:
            return @"ISK";
            
        case MPCurrencyNOK:
            return @"NOK";
            
        case MPCurrencyPLN:
            return @"PLN";
            
        case MPCurrencyRON:
            return @"RON";
            
        case MPCurrencySEK:
            return @"SEK";
            
        case MPCurrencyUSD:
            return @"USD";
            
        case MPCurrencyUnknown:
            return @"";
    }
}

@end
