//
//  myPOSService.h
//  myPOSBluetoothSDK
//
//  Copyright © 2017 Intercard Finance AD. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import <ExternalAccessory/ExternalAccessory.h>

@class MPRefundRequest;
@class MPCheckoutRequest;

/*!
 *  @enum MPDeviceMode
 *
 *  @constant MPPOSDeviceModeUnknown
 *  @constant MPPOSDeviceModeStandard
 *  @constant MPPOSDeviceModeModern
 *
 *  @discussion Parameter used during the initializaton of the SDK.
 *
 *  @see        startInitializationFromController:withCompletion:
 *  @see        initializeWithAppName:deviceMode:
 */
typedef NS_ENUM(NSUInteger, MPPOSDeviceMode) {
    MPPOSDeviceModeUnknown,
    MPPOSDeviceModeStandard,
    MPPOSDeviceModeModern,
};

/*!
 *  @enum MPCurrency
 *
 *  @discussion Available transaction currencies.
 *
 *  @constant MPCurrencyUnknown Uknown currency therefore an invalid value for a purchase/refund.
 *  @constant MPCurrencyHRK     Croatian Kuna
 *  @constant MPCurrencyCZK     Czech Koruna
 *  @constant MPCurrencyDKK     Danish Krone
 *  @constant MPCurrencyHUF     Hungarian Forint
 *  @constant MPCurrencyISK     Icelandic Krona
 *  @constant MPCurrencyNOK     Norwegian Krone
 *  @constant MPCurrencySEK     Swedish Krona
 *  @constant MPCurrencyCHF     Swiss Franc
 *  @constant MPCurrencyGBP     British Pound
 *  @constant MPCurrencyUSD     US Dolar
 *  @constant MPCurrencyRON     Romanian Leu
 *  @constant MPCurrencyBGN     Bulgarian Lev
 *  @constant MPCurrencyEUR     Euro
 *  @constant MPCurrencyPLN     Polish Zloty
 */
typedef NS_ENUM(NSInteger, MPCurrency) {
    MPCurrencyUnknown,
    MPCurrencyHRK,
    MPCurrencyCZK,
    MPCurrencyDKK,
    MPCurrencyHUF,
    MPCurrencyISK,
    MPCurrencyNOK,
    MPCurrencySEK,
    MPCurrencyCHF,
    MPCurrencyGBP,
    MPCurrencyUSD,
    MPCurrencyRON,
    MPCurrencyBGN,
    MPCurrencyEUR,
    MPCurrencyPLN,
};

/*!
 *  @discussion     An operation completion method with a nullable error.
 *                  If operation has completed successfully, the error will be nil,
 *                  otherwise will contain information what went wrong with the request.
 *
 *  @param error    An error object with more information about the error.
 */
typedef void (^MPRequestCompletion)(NSError * _Nullable error);

/*!
 *  @discussion             An operation completion method with a nullable error.
 *                          If operation has completed successfully, the error will be nil,
 *                          otherwise will contain information what went wrong with the request.
 *
 *  @param posDeviceMode    Returns the mode of the POS device with which a connection was established.
 *                          If an error occured, the mode is set to MPPOSDeviceModeUnknown
 *  @param error            An error object with more information about the error. Can be nil if no error occured.
 *
 *  @see                    MPPOSDeviceMode
 */
typedef void (^MPInitializationCompletion)(MPPOSDeviceMode posDeviceMode, NSError * _Nullable error);


@interface myPOSService : NSObject

/*!
 *  @method startInitializationFromController:withCompletion:
 *
 *  @discussion             Start initialization of the app.
 *
 *  @param  viewController  The view controller from which an initialization controller will be presented.
 *  @param  completion      A completion block that will be called upon operation completion.
 *                          Contains the POS device mode in which the SDK was initialized
 *                          or error if such occured during the initialization process.
 *
 *  @see                    MPInitializationCompletion
 */
+ (void)startInitializationFromController:(nonnull UIViewController *)viewController
                           withCompletion:(nullable MPInitializationCompletion)completion;

/*!
 *  @method startInitializationFromController:forPOSDeviceInMode:withCompletion:
 *
 *  @discussion             Start initialization of the app.
 *
 *  @param  viewController  The view controller from which an initialization controller will be presented.
 *  @param  posDeviceMode   The mode of the POS device with which to establish a connection.
 *  @param  completion      A completion block that will be called upon operation completion.
 *                          Contains the POS device mode in which the SDK was initialized
 *                          or error if such occured during the initialization process.
 *
 *  @see                    MPInitializationCompletion
 *  @see                    MPPOSDeviceMode
 */
+ (void)startInitializationFromController:(nonnull UIViewController *)viewController
                       forPOSDeviceInMode:(MPPOSDeviceMode)posDeviceMode
                           withCompletion:(nullable MPInitializationCompletion)completion;

/*!
 *  @method setAppName:
 *
 *  @discussion     Set a custom title value for the navigation's title property in the navigation bar.
 *
 *  @param  appName A custom title.
 */
+ (void)setAppName:(nullable NSString *)appName;

/*!
 *  @method checkoutWithRequest:fromViewController:completion:
 *
 *  @param  payment             Payment request object containing information about the operation.
 *  @param  viewController      The view controller from which to present the request.
 *  @param  completion          A completion block that will be called upon operation completion. Can contain error if such occured during the process.
 *
 *  @see                        MPCheckoutRequest
 *  @see                        MPRequestCompletion
 *  @seealso                    checkoutWithRequest:fromViewController:skipConfirmation:completion:
 */
+ (void)checkoutWithRequest:(nonnull MPCheckoutRequest *)payment
         fromViewController:(nonnull UIViewController *)viewController
                 completion:(nullable MPRequestCompletion)completion;

/*!
 *  @method checkoutWithRequest:fromViewController:skipConfirmation:completion:
 *
 *  @param  payment             Payment request object containing information about the operation.
 *  @param  viewController      The view controller from which to present the request.
 *  @param  skipConfirmation    Optional parameter to determine whether to allow editing of the amount after generating the request. Default is NO.
 *  @param  completion          A completion block that will be called upon operation completion. Can contain error if such occured during the process.
 *
 *  @see                        MPCheckoutRequest
 *  @see                        MPRequestCompletion
 *  @seealso                    checkoutWithRequest:fromViewController:completion:
 */
+ (void)checkoutWithRequest:(nonnull MPCheckoutRequest *)payment
         fromViewController:(nonnull UIViewController *)viewController
           skipConfirmation:(BOOL)skipConfirmation
                 completion:(nullable MPRequestCompletion)completion;

/*!
 *  @method requestRefund:fromViewController:completion:
 *
 *  @param  payment             Refund request object containing information about the operation.
 *  @param  viewController      The view controller from which to present the request.
 *  @param  completion          A completion block that will be called upon operation completion. Can contain error if such occured during the process.
 *
 *  @see                        MPRefundRequest
 *  @see                        MPRequestCompletion
 *  @seealso                    requestRefund:fromViewController:skipConfirmation:completion:
 */
+ (void)requestRefund:(nonnull MPRefundRequest *)refundRequest
   fromViewController:(nonnull UIViewController *)viewController
           completion:(nullable MPRequestCompletion)completion;

/*!
 *  @method requestRefund:fromViewController:skipConfirmation:completion:
 *
 *  @param  payment             Refund request object containing information about the operation.
 *  @param  viewController      The view controller from which to present the request.
 *  @param  skipConfirmation    Optional parameter to determine whether to allow editing of the amount after generating the request. Default is NO.
 *  @param  completion          A completion block that will be called upon operation completion. Can contain error if such occured during the process.
 *
 *  @see                        MPRefundRequest
 *  @see                        MPRequestCompletion
 *  @seealso                    requestRefund:fromViewController:completion:
 */
+ (void)requestRefund:(nonnull MPRefundRequest *)refundRequest
   fromViewController:(nonnull UIViewController *)viewController
     skipConfirmation:(BOOL)skipConfirmation
           completion:(nullable MPRequestCompletion)completion;

/*!
 *  @method requestReversalFromController:skipConfirmation:completion:
 *
 *  @param  viewController      The view controller from which to present the request.
 *  @param  skipConfirmation    Optional parameter to determine whether to allow editing of the amount after generating the request. Default is NO.
 *  @param  completion          A completion block that will be called upon operation completion. Can contain error if such occured during the process.
 *
 *  @see                        MPRequestCompletion
 *  @seealso                    requestReversalFromController:completion:
 */
+ (void)requestReversalFromController:(nonnull UIViewController *)viewController
                     skipConfirmation:(BOOL)skipConfirmation
                           completion:(nullable MPRequestCompletion)completion;

/*!
 *  @method reprintLastReceiptWithCompletion:
 *
 *  @param  completion          A completion block that will be called upon operation completion. Can contain error if such occured during the process.
 *
 *  @see                        MPRequestCompletion
 */
+ (void)reprintLastReceiptWithCompletion:(nullable MPRequestCompletion)completion;

/*!
 *  @method requestActivateTerminalFromController:withCompletion:
 *
 *  @discussion                 Start terminal activateion process. An activation code will need to be entered on the device.
 *
 *  @param  viewController      The view controller from which to present the request.
 *  @param  completion          A completion block that will be called upon operation completion. Can contain error if such occured during the process.
 *
 *  @see                        MPRequestCompletion
 */
+ (void)requestActivateTerminalFromController:(nonnull UIViewController *)viewController
                               withCompletion:(nullable MPRequestCompletion)completion;

/*!
 *  @method requestUpdateTerminalFromController:withCompletion:
 
 *  @discussion                 Check whether an update is available and prompt user to accept or decline the update.
 *
 *  @param  viewController      The view controller from which to present the request.
 *  @param  completion          A completion block that will be called upon operation completion. Can contain error if such occured during the process.
 *
 *  @see                        MPRequestCompletion
 */
+ (void)requestUpdateTerminalFromController:(nonnull UIViewController *)viewController
                             withCompletion:(nullable MPRequestCompletion)completion;

/*!
 *  @method requestDeactivateTerminalFromController:withCompletion:
 *
 *  @discussion                 Start terminal deactivation process. A deactivation code will need to be entered on the device.
 *
 *  @param  viewController      The view controller from which to present the request.
 *  @param  completion          A completion block that will be called upon operation completion. Can contain error if such occured during the process.
 *
 *  @see                        MPRequestCompletion
 */
+ (void)requestDeactivateTerminalFromController:(nonnull UIViewController *)viewController
                                 withCompletion:(nullable MPRequestCompletion)completion;

@end
