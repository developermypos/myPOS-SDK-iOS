//
//  ViewController.m
//  myPOSServiceDemo
//
//  Created by Valio Cholakov on 6/14/17.
//  Copyright © 2017 Intercard Finance AD. All rights reserved.
//

#import <myPOSBluetoothSDK/myPOSBluetoothSDK.h>

#import "ViewController.h"

#import "UIAlertController+Helpers.h"

@interface ViewController() {
    BOOL _initialized;
}

@end

@implementation ViewController

#pragma mark - Controller Methods

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [myPOSService setAppName:@"myPOS Service Demo"];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    _initialized = NO;
}

static NSString * const kInitializedSegue = @"initialized";

#pragma mark - Actions

- (IBAction)standard:(id)sender {
    [self initializeSDKForDeviceMode:MPPOSDeviceModeModern];
}

- (IBAction)modern:(id)sender {
    [self initializeSDKForDeviceMode:MPPOSDeviceModeModern];
}

- (IBAction)startInitialization:(id)sender {
    [self initializeSDKForDeviceMode:MPPOSDeviceModeUnknown];
}

- (IBAction)wifi:(id)sender {
    UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"Connect through WIFI" message:@"POS device host and port:" preferredStyle:UIAlertControllerStyleAlert];
    [alertController addTextFieldWithConfigurationHandler:^(UITextField * _Nonnull textField) {
        textField.placeholder = @"host:port";
    }];
    UIAlertAction *confirmAction = [UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [self initializeSDKWithURL:[[alertController textFields][0] text]];
    }];
    [alertController addAction:confirmAction];
    UIAlertAction *cancelAction = [UIAlertAction actionWithTitle:@"Cancel" style:UIAlertActionStyleCancel handler:^(UIAlertAction * _Nonnull action) {
        NSLog(@"Canelled");
    }];
    [alertController addAction:cancelAction];
    [self presentViewController:alertController animated:YES completion:nil];
}

#pragma mark - Private Methods

- (void)initializeSDKForDeviceMode:(MPPOSDeviceMode)mode {
    [myPOSService startInitializationFromController:self
                                 forPOSDeviceInMode:mode
                                     withCompletion:^(MPPOSDeviceMode posDeviceMode, NSError * _Nullable error) {
                                         _initialized = error == nil;
        
                                         error ? [UIAlertController showAlertWithTitle:@"Error" message:error.localizedDescription fromController:self]
                                               : [self performSegueWithIdentifier:kInitializedSegue sender:self];
                                     }];
}

- (void)initializeSDKWithURL:(NSString *)url {
    [myPOSService startInitializationFromController:self
                                             forURL:url
                                     withCompletion:^(MPPOSDeviceMode posDeviceMode, NSError * _Nullable error) {
                                         _initialized = error == nil;
        
                                         error ? [UIAlertController showAlertWithTitle:@"Error" message:error.localizedDescription fromController:self]
                                               : [self performSegueWithIdentifier:kInitializedSegue sender:self];
                                     }];
}


@end
