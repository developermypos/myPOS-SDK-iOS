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
    [myPOSService setDefaultPOSDeviceSerialNumber:@"5A333906"];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    _initialized = NO;
}

static NSString * const kInitializedSegue = @"initialized";

#pragma mark - Actions

- (IBAction)standard:(id)sender {
    [self initializeSDKForDeviceMode:MPPOSDeviceModeStandard];
}

- (IBAction)modern:(id)sender {
    [self initializeSDKForDeviceMode:MPPOSDeviceModeModern];
}

- (IBAction)startInitialization:(id)sender {
    [self initializeSDKForDeviceMode:MPPOSDeviceModeUnknown];
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

@end
