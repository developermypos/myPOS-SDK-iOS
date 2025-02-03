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
@class MPReceiptData;
@class MPTransactionData;

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
    MPPOSDeviceModeWifi,
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
 *  @enum MPLanguage
 *
 *  @discussion Available interface languages.
 */
typedef NS_ENUM(int, MPLanguage) {
    MPLanguageEnglish,
    MPLanguageBulgarian,
    MPLanguageItalian,
    MPLanguageCroatian,
    MPLanguageSpanish,
    MPLanguageGerman,
    MPLanguageFrench,
    MPLanguageRomanian,
    MPLanguageGreek,
    MPLanguageNetherlandish,
    MPLanguageLatvian,
    MPLanguageSwedish,
    MPLanguagePortuguese,
    MPLanguageIcelandic,
    MPLanguageSlovenian,
    MPLanguageCzech,
    MPLanguageLithuanian,
    MPLanguagePolish,
    MPLanguageHungarian
};

/*!
 *  @enum MPDeviceReceipt
 *
 *  @discussion Available receipt types for devices with a printer.
 *
 *  @constant MPDeviceReceiptPrintAutomatically     Let the device decice. This is the default setting.
 *  @constant MPDeviceReceiptPrintAfterConfirmation The device will prompt whether to print a customer copy of the receipt.
 *  @constant MPDeviceReceiptPrintOnlyMerchantCopy  Do not print customer copy.
 *  @constant MPDeviceReceiptDoNotPrint             Do not print receipt at all.
 *  @constant MPDeviceReceiptElectron               Send a e-receipt. Available only for devices without a printer.
 */
typedef NS_ENUM(int, MPDeviceReceipt) {
    MPDeviceReceiptPrintAutomatically,
    MPDeviceReceiptPrintAfterConfirmation,
    MPDeviceReceiptPrintOnlyMerchantCopy,
    MPDeviceReceiptDoNotPrint,
    MPDeviceReceiptElectron,
};

/*!
 *  @enum MPReferenceType
 *
 *  @discussion Set the type of the reference for financial operations. Default is number.
 */
typedef NS_ENUM(int, MPReferenceType) {
    MPReferenceTypeUnknown,
    MPReferenceTypeNumber,
    MPReferenceTypeInvoiceId,
    MPReferenceTypeProductId,
    MPReferenceTypeReservationNumber,
};

/*!
 *  @enum PosStatus
 *
 *  @discussion POS Status types depending on the stage and status of each method
 */
typedef NS_ENUM(int, PosStatus) {
    POS_STATUS_SUCCESS                                  = 0,
    POS_STATUS_PENDING_USER_INTERACTION                 = 1,
    POS_STATUS_USER_CANCEL                              = 2,
    POS_STATUS_INTERNAL_ERROR                           = 3,
    POS_STATUS_TERMINAL_BUSY                            = 4,
    POS_STATUS_UNSUPPORTED_SDK_VERSION                  = 5,
    POS_STATUS_NO_UPDATE_FOUND                          = 6,
    POS_STATUS_MANDATORY_UPDATE                         = 7,
    POS_STATUS_OPTIONAL_UPDATE                          = 8,
    POS_STATUS_POS_UPDATING                             = 9,
    POS_STATUS_ACTIVATION_REQUIRED                      = 10,
    POS_STATUS_PROCESSING                               = 11,
    POS_STATUS_DEACTIVATION_NOT_COMPLETED               = 12,
    POS_STATUS_ACTIVATION_NOT_REQUIRED                  = 13,
    POS_STATUS_ACTIVATION_NOT_COMPLETED                 = 14,
    POS_STATUS_WRONG_ACTIVATION_CODE                    = 15,
    POS_STATUS_WRONG_DEACTIVATION_CODE                  = 16,
    POS_STATUS_WAIT_ACTIVATION_CODE                     = 17,
    POS_STATUS_WAIT_DEACTIVATION_CODE                   = 18,
    POS_STATUS_UPDATE_NOT_COMPLETED                     = 19,
    POS_STATUS_TRANSACTION_NOT_FOUND                    = 20,
    POS_STATUS_NO_PRINTER_AVAILABLE                     = 21,
    POS_STATUS_NO_PAPER                                 = 22,
    POS_STATUS_WRONG_AMOUNT                             = 23,
    POS_STATUS_NO_CARD_FOUND                            = 24,
    POS_STATUS_NOT_SUPPORTED_CARD                       = 25,
    POS_STATUS_CARD_CHIP_ERROR                          = 26,
    POS_STATUS_INVALID_PIN                              = 27,
    POS_STATUS_MAX_PIN_COUNT_EXCEEDED                   = 28,
    POS_STATUS_PIN_CHECK_ONLINE                         = 29,
    POS_STATUS_SUCCESS_ACTIVATION                       = 31,
    POS_STATUS_SUCCESS_DEACTIVATION                     = 32,
    POS_STATUS_SUCCESS_UPDATE                           = 33,
    POS_STATUS_SUCCESS_PURCHASE                         = 34,
    POS_STATUS_SUCCESS_REFUND                           = 35,
    POS_STATUS_SUCCESS_REPRINT_RECEIPT                  = 37,
    POS_STATUS_DOWNLOADING_CERTIFICATES_IN_PROGRESS     = 38,
    POS_STATUS_DOWNLOADING_CERTIFICATES_COMPLETED       = 39,
    POS_STATUS_INCORRECT_PRINT_DATA                     = 40,
    POS_STATUS_INCORRECT_LOGO_INDEX                     = 41,
    POS_STATUS_SUCCESS_PRINT_RECEIPT                    = 42,
    POS_STATUS_INVALID_OR_MISSING_PREAUTH_CODE          = 43,
    POS_STATUS_INVALID_PREAUTH_AMOUNT                   = 44,
    POS_STATUS_PREAUTH_TRAN_BEEN_COMPLETED              = 45,
    POS_STATUS_INVALID_PAN                              = 46,
    POS_STATUS_INVALID_EXP_DATE                         = 47,
    POS_STATUS_PREAUTH_COMPLETING                       = 48,
    POS_STATUS_PREAUTH_CANCELING                        = 49,
    POS_STATUS_SUCCESS_PREAUTH_COMPLETION               = 50,
    POS_STATUS_SUCCESS_PREAUTH_CANCELLATION             = 51,
    POS_STATUS_GIFTCARD_ACTIVATING                      = 52,
    POS_STATUS_GIFTCARD_DEACTIVATING                    = 53,
    POS_STATUS_GIFTCARD_BALANCE_CHECK                   = 54,
    POS_STATUS_SUCCESS_GIFTCARD_ACTIVATION              = 55,
    POS_STATUS_SUCCESS_GIFTCARD_DEACTIVATION            = 56,
    POS_STATUS_SUCCESS_GIFTCARD_BALANCE_CHECK           = 57,
    POS_STATUS_WRONG_TIPPING_AMOUNT                     = 58,
    POS_STATUS_WRONG_PASSWORD                           = 59,
    POS_STATUS_REVERSING_TRANSACTION                    = 60,
    POS_STATUS_SUCCESS_REVERSAL                         = 61,
    POS_STATUS_REVERSAL_NOT_FOUND                       = 62,
    POS_STATUS_INVALID_OPERATOR_CODE                    = 63,
    POS_STATUS_INVALID_REFERENCE_NUMBER_TYPE            = 64,
    POS_STATUS_INVALID_REFERENCE_NUMBER                 = 65,
    POS_STATUS_PREAUTH_NOT_SUPPORTED_PARAM              = 66,
    POS_STATUS_PAYMENT_REQUEST_WRONG_RECIPIENT          = 67,
    POS_STATUS_PAYMENT_REQUEST_INVALID_EXP_DAYS         = 68,
    POS_STATUS_PAYMENT_INVALID_REQUEST_CODE             = 69,
    POS_STATUS_TRANSACTION_FORBIDDEN                    = 70,
    POS_STATUS_SUCCESS_PREAUTH                          = 71,
    POS_STATUS_SUCCESS_PING                             = 72,
    POS_STATUS_PING_FAILED                              = 73,
    POS_STATUS_PRESENT_CARD_SCREEN                      = 74,
    POS_STATUS_SELECT_DCC_SCREEN                        = 75,
    POS_STATUS_ENTER_PIN_SCREEN                         = 76,
    POS_STATUS_DCC_BEEN_SELECTED                        = 77,
    POS_STATUS_PASSWORD_REQUIRED                        = 78,
    POS_STATUS_COM_ERROR                                = 79,
    POS_STATUS_UNKNOWN                                  = 80,
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

@protocol MPServiceDelegate <NSObject>
@optional

- (void)didReceiveStageInfo:(PosStatus)posInfo;

@end

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
 *  @param  check      Is it just checking for already paired device
 *  @param  posDeviceMode   The mode of the POS device with which to establish a connection.
 *  @param  completion      A completion block that will be called upon operation completion.
 *                          Contains the POS device mode in which the SDK was initialized
 *                          or error if such occured during the initialization process.
 *
 *  @see                    MPInitializationCompletion
 *  @see                    MPPOSDeviceMode
 */
+ (void)startInitializationFromController:(nonnull UIViewController *)viewController
                     checkingPairedDevice:(BOOL)check
                       forPOSDeviceInMode:(MPPOSDeviceMode)posDeviceMode
                           withCompletion:(nullable MPInitializationCompletion)completion;

/*!
 *  @method startInitializationFromController:forPOSDeviceInMode:withCompletion:
 *
 *  @discussion             Start initialization of the app.
 *
 *  @param  viewController  The view controller from which an initialization controller will be presented.
 *  @param  url   The host and port of the POS device with which to establish a connection.
 *  @param  completion      A completion block that will be called upon operation completion.
 *                          Contains the POS device mode in which the SDK was initialized
 *                          or error if such occured during the initialization process.
 *
 *  @see                    MPInitializationCompletion
 *  @see                    MPPOSDeviceMode
 */
+ (void)startInitializationFromController:(nonnull UIViewController *)viewController
                                   forURL:(nonnull NSString *)url
                           withCompletion:(nullable MPInitializationCompletion)completion;

- (void)setDelegate:(nullable id<MPServiceDelegate>)delegate;

/*!
 *  @method setDelegate:
 *
 *  @discussion Set a delegate object..
 *
 *  @param  delegate A delegate.
 */
+ (void)setDelegate:(nullable id<MPServiceDelegate>)delegate;

/*!
 *  @method setAppName:
 *
 *  @discussion Set a custom title value for the navigation's title property in the navigation bar.
 *
 *  @param  appName A custom title.
 */
+ (void)setAppName:(nullable NSString *)appName;

/*!
 *  @method setLanguage:
 *
 *  @discussion Set a preferred language for the POS operations.
 *
 *  @param  preferredLanguage A language option from the enumerator.
 */
+ (void)setPreferredLanguage:(MPLanguage)preferredLanguage;

/*!
 *  @method setDefaultPOSDeviceSerialNumber:
 *
 *  @discussion Set the serial number of a POS device to which to connect automatically upon discovery.
 *
 *  @param  serialNumber The serial number of a POS device.
 */
+ (void)setDefaultPOSDeviceSerialNumber:(nullable NSString *)serialNumber;

/*!
 *  @method terminalId:
 *
 *  @discussion Gets the connected POS terminal TID if available
 */
+ (nullable NSString *)terminalId;

/*!
 *  @method preferredLanguage:
 *
 *  @discussion Gets the preferred language for the POS operations.
 */
+ (MPLanguage)preferredLanguage;

/*!
 *  @method defaultSerialNumber:
 *
 *  @discussion Getter for the default serial number of a POS device.
 */
+ (NSString * _Nullable)defaultSerialNumber;

/*!
 *  @method lastTranscationData:
 *
 *  @discussion Getter for the data of the last processed transaction on the POS device.
 */
+ (MPTransactionData * _Nullable)lastTranscationData;

/*!
 *  @method setReceiptType:
 *
 *  @discussion Set a receipt print setting. If the device is has no printer, the parameter will be ignored.
 *
 *  @param  receiptType The device print receipt type.
 */
+ (void)setReceiptType:(MPDeviceReceipt)receiptType;

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
 *  @method quickCheckoutWithRequest:fromViewController:completion:
 *
 *  @param  payment                     Payment request object containing information about the operation.
 *  @param  viewController     The view controller on which a loading HUD will be displayed. A new view controller will not be presented on top of it.
 *  @param  completion              A completion block that will be called upon operation completion. Can contain error if such occured during the process.
 *
 *  @see                        MPCheckoutRequest
 *  @see                        MPRequestCompletion
 */
+ (void)quickCheckoutWithRequest:(nonnull MPCheckoutRequest *)payment
              fromViewController:(nonnull UIViewController *)viewController
                      completion:(nullable MPRequestCompletion)completion;

/*!
 *  @method requestRefund:fromViewController:completion:
 *
 *  @param  refundRequest         Refund request object containing information about the operation.
 *  @param  viewController      The view controller from which to present the request.
 *  @param  completion               A completion block that will be called upon operation completion. Can contain error if such occured during the process.
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
 *  @param  refundRequest            Refund request object containing information about the operation.
 *  @param  viewController         The view controller from which to present the request.
 *  @param  skipConfirmation     Optional parameter to determine whether to allow editing of the amount after generating the request. Default is NO.
 *  @param  completion                  A completion block that will be called upon operation completion. Can contain error if such occured during the process.
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
 *  @method requestQuickRefund:fromViewController:skipConfirmation:completion:
 *
 *  @param  refundRequest        Refund request object containing information about the operation.
 *  @param  viewController      The view controller on which a loading HUD will be displayed. A new view controller will not be presented on top of it.
 *  @param  completion               A completion block that will be called upon operation completion. Can contain error if such occured during the process.
 *
 *  @see                        MPRefundRequest
 *  @see                        MPRequestCompletion
 */
+ (void)requestQuickRefund:(nonnull MPRefundRequest *)refundRequest
        fromViewController:(nonnull UIViewController *)viewController
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
*  @method printReceipt:completion:
*
*  @param receiptData          The receipt data to be printed
*  @param  completion          A completion block that will be called upon operation completion. Can contain error if such occured during the process.
*
*  @see                        MPRequestCompletion
*/
+ (void)printReceipt:(nonnull MPReceiptData *)receiptData completion:(nullable MPRequestCompletion)completion;

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

/*!
 *  @method hasPrinter:
 *
 *  @discussion Determine whether the POS device has a printer available.
 */
+ (BOOL)hasPrinter;

/*!
 *  @method isConnected:
 *
 *  @discussion Determine whether there is an active connection to a POS device.
 */
+ (void)isConnectedFromViewController:(nonnull UIViewController *)viewController
                           completion:(nullable MPRequestCompletion)completion;

/*!
 *  @method unpairDevice:
 *
 *  @discussion Unpair currently connected POS device.
 */
+ (void)unpairDeviceWithCompletion:(nullable MPRequestCompletion)completion;

@end
