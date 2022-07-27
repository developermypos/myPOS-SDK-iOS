//
//  MPReceiptData.h
//  myPOSBluetoothSDK
//
//  Created by Valio Cholakov on 10.03.20.
//  Copyright © 2020 myPOS. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface MPReceiptData : NSObject

typedef NS_ENUM(int, MPReceiptTextAlign) {
    MPReceiptTextAlignLeft   = 1,
    MPReceiptTextAlignCenter = 2,
    MPReceiptTextAlignRight  = 3,
};

typedef NS_ENUM(int, MPReceiptTextFontSize) {
    MPReceiptTextFontSizeSingle = 1,
    MPReceiptTextFontSizeDouble = 3,
};

- (void)addLogo:(int)logoIndex;
- (void)addEmptyRow;
- (void)addRowWithText:(NSString *)text;
- (void)addRowWithText:(NSString *)text aligned:(MPReceiptTextAlign)alignment withFontSize:(MPReceiptTextFontSize)fontSize;
- (NSString *)receiptData;

@end

NS_ASSUME_NONNULL_END
