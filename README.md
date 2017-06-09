

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

Installation

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

# Installation

## Preparing your Xcode project

1. Add the myPOSService.framework to your Xcode project.
2. Link your app against myPOSService.framework.

## Privacy Info plist keys

NSBluetoothPeripheralUsageDescription

Note:
You can use the [sample app](https://github.com/developermypos/repo1/tree/master/myPOSServiceDemo) that is provided with the myPOS SDK iOS as a reference project.

iOS SDK enabling to integrate Apps with myPOS Card Terminals for Card Payments processing

# Initialization

## Make sure the framework is imported.

### **Objective-C**

#import &lt;myPOSBluetoothSDK/myPOSService.h&gt;

### **Swift**

If you are using swift, you will need to create a bridging header and import the framework there. For more information about bridging headers, please visit [Apple&#39;s documentation](https://developer.apple.com/library/content/documentation/Swift/Conceptual/BuildingCocoaApps/MixandMatch.html).

## Call the initialization method

Call the initialization method while passing the currency for financial operations (purchase, refund, etc.)

### **Objective-C**

[myPOSService initializeWithCurrency:ICTerminalCurrencyEUR delegate:self];

### **Swift**

myPOSService.initialize(withCurrency: ICTerminalCurrencyEUR, delegate: self)

## Currency change if needed

If at some point the currency needs to be changed, the below method can be used to set the new currency.

**Objective-C**

[myPOSService changeCurrency:newCurrency];

**Swift**

myPOSService.changeCurrency(newCurrency)

## Common delegate Methods

**Objective-C**

- (void)serviceDidStart;

- (void)serviceDidStop;

- (void)posReadyToProcessCommands;

- (void)didReceiveInfoFromTerminal:(NSNumber \*)informationCode;

**Swift**

func serviceDidStart() { }

func serviceDidStop() { }

func didReceiveInfo(fromTerminal informationCode: NSNumber) { }

func posReadyToProcessCommands() { }

# Manage Card terminal

1. 1.Activate terminal:

Before using terminal for a first time the SDK has to initiate Terminal activation, which will setup terminal for processing transaction, setting up Terminal ID, Merchant ID etc.

### **Example:**

### **Objective-C**

[myPOSService activateTerminalWithOnSuccess:^{

} onError:^(NSError \* \_Nonnull error) {

}];

### **Swift**

myPOSService.activateTerminalWith(onSuccess: {

}) { (error) in

}

1. 2.Update terminal software:

Each time terminal processing transaction, processor host checks for existing pending updates, and inform terminal if any. In that case by this method software update is activated, and terminal is going in the update mode.

### **Example:**

### Objective-C

[myPOSService updateTerminalWithOnSuccess:^{

} onError:^(NSError \* \_Nonnull error) {

}];

### Swift

myPOSService.updateTerminalWith(onSuccess: {

}) { (error) in

}

1. 3.Deactivate terminal:

### **Example:**

### **Objective-C**

[myPOSService deactivateTerminalWithOnSuccess:^{

} onError:^(NSError \* \_Nonnull error) {

}];

### **Swift**

myPOSService.deactivateTerminalWith(onSuccess: {

}) { (error) in

}

# Payment processing

1. 1.Make payment

Once initialization is completed, you can start using the myPOS SDK iOS to accept card payments.

Host application has to specify amount of the transaction, print slip option – automated print of the slip after transaction, or without automated printing.

Make purchase request, encapsulates information regarding the transaction and start payment by using the Make purchase request below:

### **Example:**

**Objective-C**

[myPOSService makePurchaseFor:@&quot;1.00&quot;

                    onSuccess:^{

                    } onError:^(NSError \* \_Nonnull error) {

                    }];

**Swift**

myPOSService.makePurchase(for: &quot;1.00&quot;, onSuccess: {

}) { (error) in

}

1. 2.Make reversal:

With this method host application could initiate reversal of the last transaction.

### **Example:**

**Objective-C**

[myPOSService makeReversalWith

                OnSuccess:^{

                } onError:^(NSError \* \_Nonnull error) {

                }];

### **Swift**

myPOSService.makeReversalWith(onSuccess: {

}) { (error) in

}

1. 3.Make refund:

With this method host application could initiate refund transaction to the customers&#39; card account with the specified amount.

### **Example:**

### **Objective-C**

[myPOSService makeRefundFor:@&quot;1.00&quot;

                  onSuccess:^{

                  } onError:^(NSError \* \_Nonnull error) {

                  }];

### **Swift**

myPOSService.makeRefund(for: &quot;1.00&quot;, onSuccess: {

}) { (error) in

}

1. 4.Reprint last receipt:

With this method host application could request reprint of last transaction slip.

### **Example:**

### **Objective-C**

[myPOSService reprintLastReceiptWithOnSuccess:^{

} onError:^(NSError \* \_Nonnull error) {

}];

### **Swift**

myPOSService.reprintLastReceiptWith(onSuccess: {

}) { (error) in

}

