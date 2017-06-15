

# myPOS SDK iOS

This repository provides a native iOS SDK, which enables to integrate your Mobile App with myPOS Card terminals, processed by its platform, to accept card payments (including but not limited to VISA, Mastercard, UnionPay International, JCB, Bancontact). myPOS SDK iOS communicates transparently to the card terminal(s) via Bluetooth. To process checkout SDK provides management of the terminal to complete all the steps for transaction processing, return or refund, card storage for recurring transactions, and communicates to the application transaction status, card token, card masked PAN.

No sensitive card data is ever passed through to or stored on the merchant&#39;s phone. All data is encrypted by the card terminal, which has been fully certified to the highest industry standards (PCI, EMV I &amp; II, Visa, MasterCard &amp; Amex).

### Prerequisites

1. Merchant account on [eu](https://www.mypos.eu/) (or received a test account).
2. Received myPOS terminal
3. Requested Access   [Developers myPOS](http://developers.mypos.eu) site.
4. Deployment Target iOS 6.0 or later.
5. Xcode 7 and iOS SDK 9 or later.
6. iPhone or iPad.

### Table of Contents

[Installation](#Installation)

Preparing your Xcode project

Privacy Info plist keys

Initialization

Make sure the framework is imported.

Call the initialization method

Currency change if needed

Common delegate Methods

Manage Card terminal

1.        Activate terminal

2.        Update terminal software

3.        Deactivate terminal

Payment processing

1.        Make payment

2.        Make reversal

3.        Make refund

4.        Reprint last receipt

## Installation

# Preparing your Xcode project
1.	Add the myPOSService.framework to your Xcode project.
2.	Link your app against myPOSService.framework.

# Privacy Info plist keys
NSBluetoothPeripheralUsageDescription

# Initialization
Make sure the framework is imported.

### Objective-C
```obj-c
#import <myPOSBluetoothSDK/myPOSBluetoothSDK.h>
```
### Swift
If you are using swift, you will need to create a bridging header and import the framework there. For more information about bridging headers, please visit  [Apple's documentation](https://developer.apple.com/library/content/documentation/Swift/Conceptual/BuildingCocoaApps/MixandMatch.html).

Call the initialization method while passing the currency for financial operations (purchase, refund, etc.)
### Objective-C
```obj-c                                                                    
[myPOSService startInitializationFromController:self
                                 withCompletion:^(MPPOSDeviceMode posDeviceMode, NSError * _Nullable error) {
                                     
                                 }];
```
### Swift
```Swift
myPOSService.startInitialization(from: self) { (posDeviceMode, error) in

}
```


## You can set a custom navigation title in the SDK screens, by using the method below:
### Objective-C
```obj-c
[myPOSService setAppName:@"My App Name"];
```
### Swift
```swift
myPOSService.setAppName("My App Name")
```


# Checkout/Refund requests
A checkout and refund request are generated identiacally by passing an amount, currency, and item name.
## 1. Checkout request
### Objective-C
```obj-c
MPCheckoutRequest *checkoutRequest = [MPCheckoutRequest requestWithTotal:[NSDecimalNumber decimalNumberWithString:@"1.00"]
                                                                   title:@"Some item"
                                                                currency:MPCurrencyEUR];
```
### Swift
```swift
let checkoutRequest = MPCheckoutRequest(total: NSDecimalNumber(string: "1.00"),
                                        title: "Some item",
                                        currency: .EUR)
```

## 2. Refund request
### Objective-C
```obj-c
MPRefundRequest *refundRequest = [MPRefundRequest requestWithTotal:[NSDecimalNumber decimalNumberWithString:@"1.00"]
                                                             title:@"Some item"
                                                          currency:MPCurrencyEUR];
```
### Swift
```swift
let refundRequest = MPRefundRequest(total: NSDecimalNumber(string: "1.00"),
                                    title: "Some item",
                                    currency: .EUR)
```

Please note that you need to pass an ```NSDecimalNumber``` as the total value. While ```NSDecimalNumber``` is a subclass of ```NSNumber``` it is not advised to use the convenience method of ```NSNumber``` to create an ```NSDecimalNumber```

##### An optional transaction reference of type ```NSString``` can be passed to the request.
### Objective-C
```obj-c
[request setTransactionReference:@"my_transaction_reference"];
```
### Swift
```swift
request.setTransactionReference("my_transaction_reference")
```


# POS Commands
## 1. Make purchase example:
### Objective-C
```obj-c                                                                
[myPOSService checkoutWithRequest:checkoutRequest
               fromViewController:self
                       completion:^(NSError * _Nullable error) {
                           
                       }];
```
### Swift
```Swift


myPOSService.checkout(with: checkoutRequest, from: self) { (error) in
    
}
```


## 2. Make refund example:
### Objective-C
```obj-c
[myPOSService requestRefund:refundRequest
         fromViewController:self
                 completion:^(NSError * _Nullable error) {
                     
                 }];
```
### Swift
```Swift
myPOSService.requestRefund(refundRequest, from: self) { (error) in
    
}
```

## 3. Update terminal software:
### Objective-C
```obj-c
[myPOSService requestUpdateTerminalFromController:self withCompletion:^(NSError * _Nullable error) {
    
}];
```
### Swift
```Swift
myPOSService.requestUpdateTerminal(from: self) { (error) in
    
}
```

## 4. Activate terminal:
### Objective-C
```obj-c
[myPOSService requestActivateTerminalFromController:self withCompletion:^(NSError * _Nullable error) {
    
}];
```
### Swift
```Swift
myPOSService.requestActivateTerminal(from: self) { (error) in
    
}
```

## 5. Deactivate terminal:
### Objective-C
```obj-c
[myPOSService requestDeactivateTerminalFromController:self withCompletion:^(NSError * _Nullable error) {
    
}];
```
### Swift
```Swift
myPOSService.requestDeactivateTerminal(from: self) { (error) in
    
}
```

## 6. Reprint last receipt:
### Objective-C
```obj-c
[myPOSService reprintLastReceiptWithCompletion:^(NSError * _Nullable error) {
    
}];
```
### Swift
```Swift
myPOSService.reprintLastReceipt { (error) in
    
}
```
