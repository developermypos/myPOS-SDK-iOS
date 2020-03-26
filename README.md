

# myPOS SDK iOS

This repository provides a native iOS SDK, which enables to integrate your Mobile App with myPOS Card terminals, processed by its platform, to accept card payments (including but not limited to VISA, Mastercard, UnionPay International, JCB, Bancontact). myPOS SDK iOS communicates transparently to the card terminal(s) via Bluetooth. To process checkout SDK provides management of the terminal to complete all the steps for transaction processing, return or refund, card storage for recurring transactions, and communicates to the application transaction status, card token, card masked PAN.

No sensitive card data is ever passed through to or stored on the merchant&#39;s phone. All data is encrypted by the card terminal, which has been fully certified to the highest industry standards (PCI, EMV I &amp; II, Visa, MasterCard &amp; Amex).

### Prerequisites

1. Merchant account on [www.myPOS.eu](https://www.mypos.eu/) (or received a test account).
2. Received myPOS terminal
3. Requested Access   [Developers myPOS](http://developers.mypos.eu) site.
4. Deployment Target iOS 6.0 or later.
5. Xcode 7 and iOS SDK 9 or later.
6. iPhone or iPad.

### Table of Contents

* [Installation](#installation)
  * [Preparing your Xcode project](#preparing-your-xcode-project)
  * [Privacy Info plist keys](#privacy-info-plist-keys)
* [Initialization](#initialization)
  * [Make sure the framework is imported](#make-sure-the-framework-is-imported)
  * [Call the initialization method](#call-the-initialization-method)
  * [Custom navigation title](#custom-navigation-title)
* [Payment request](#payment-request)  
  * [Checkout requests](#checkout-requests)
  * [Refund request](#refund-requst)  
  * [Initiate checkout request](#initiate-checkout-request)
  * [Initiate refund request](#initiate-refund-request)
  * [Print custom receipt](#print-custom-receipt)
  * [Reprint last receipt](#reprint-last-receipt)
* [Terminal mangement](#terminal-management)
  * [Activate terminal](#activate-terminal)
  * [Update terminal software](#update-terminal-software)
  * [Deactivate terminal](#deactivate-terminal)
* [Utilities](#utilities)
  * [Default POS device serial number](#default-pos-device-serial-number)
  * [Preferred language](#preferred-language)
  * [myPOS Terminal ID](#mypos-terminal-id)
  * [Last Transaction Data](#last-transaction-data)
  
  
  
# Installation

## Preparing your Xcode project
1.	Add the myPOSService.framework to your Xcode project.
2.	Link your app against myPOSService.framework.

## Privacy Info plist keys
NSBluetoothPeripheralUsageDescription

# Initialization
## Make sure the framework is imported

### Objective-C
```obj-c
#import <myPOSBluetoothSDK/myPOSBluetoothSDK.h>
```
### Swift
If you are using swift, you will need to create a bridging header and import the framework there. For more information about bridging headers, please visit  [Apple's documentation](https://developer.apple.com/library/content/documentation/Swift/Conceptual/BuildingCocoaApps/MixandMatch.html).

##Call the initialization method
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


## Custom navigation title
You can set a custom navigation title in the SDK screens, by using the method below:
### Objective-C
```obj-c
[myPOSService setAppName:@"My App Name"];
```
### Swift
```swift
myPOSService.setAppName("My App Name")
```


# Payment requests
Once initialization is completed, you can start using the myPOS SDK iOS to accept card payments.
Host application has to specify amount of the transaction, with automated print of the slip after transaction. 
A checkout and refund request are generated identiacally by passing an amount, currency, and item name

## Checkout request
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

## Refund request
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

## Initiate checkout request

ith this method host application initates checkout command to th terminal. 

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


## Initiate refund request

With this method host application could initiate refund transaction to the customers’ card account with the specified amount.

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

## Print custom receipt

With this method host application could request print of custom receipt.. 

### Objective-C
```obj-c
MPReceiptData *receiptData = [[MPReceiptData alloc] init];
[receiptData addRowWithText:@"Some text"];
[receiptData addEmptyRow];
[receiptData addRowWithText:@"Center text!" aligned:MPReceiptTextAlignCenter withFontSize:MPReceiptTextFontSizeDouble];

[myPOSService printReceipt:receiptData completion:^(NSError * _Nullable error) {
    
}];
```
### Swift
```Swift
let receiptData = MPReceiptData()
receiptData.addRow(withText: "Normal row")
receiptData.addEmptyRow()
receiptData.addRow(withText: "Center text!", aligned: .center, with: .double)

myPOSService.printReceipt(receiptData) { (error) in
    
}
```


## Reprint last receipt

With this method host application could request reprint of last transaction slip. 

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


# Terminal management

## Activate terminal

Before using terminal for a first time the SDK has to initiate Terminal activation, which will setup terminal for processing transaction, setting up Terminal ID, Merchant ID etc. 

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
## Update terminal software

Each time terminal processing transaction, processor host checks for existing pending updates, and inform terminal if any. In that case by this method software update is activated, and terminal is going in the update mode. 

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


## Deactivate terminal

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

# Utilities

## Default POS device serial number
You can get/set a default serial number of a myPOS terminal to which to connect upon discovery
### Objective-C
```obj-c
[myPOSService defaultSerialNumber];
[myPOSService setDefaultPOSDeviceSerialNumber:@""];
```
### Swift
```swift
myPOSService.defaultSerialNumber()
myPOSService.setDefaultPOSDeviceSerialNumber("")
```

## Preferred language
You can get/set a prefered language for the POS device screens, by using the method below:
### Objective-C
```obj-c
[myPOSService preferredLanguage];
[myPOSService setPreferredLanguage:MPLanguageEnglish];
```
### Swift
```swift
myPOSService.preferredLanguage()
myPOSService.setPreferredLanguage(.english)
```

## myPOS Terminal ID
You can get the terminal ID of the connected myPOS device, by using the method below:
### Objective-C
```obj-c
[myPOSService terminalId];
```
### Swift
```swift
myPOSService.terminalId()
```


## Last Transaction Data
You can get the data of the last processed trnasaction on the POS device, by using the method below:
### Objective-C
```obj-c
[myPOSService lastTransactionData];
```
### Swift
```swift
myPOSService.lastTransactionData()
```
