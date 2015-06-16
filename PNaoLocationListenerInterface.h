//
//  PNaoLocationListener.h
//  NaoLocationService
//
//  This protocol is equivalent to INaoLocationListener.aidl present for the Android platform.
//  It defines an interface from the service to the application.
//
//  Created by Stéphane Terrenoir on 20/08/10.
//  Copyright Pole Star SA 2010. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>

@protocol PNaoLocationListenerInterface <NSObject>
#pragma mark External API available to all applications
typedef enum {
    PNAOLOCATIONSERVICE_STATE_OUT_OF_SERVICE = 0,
    PNAOLOCATIONSERVICE_STATE_TEMPORARILY_UNAVAILABLE,
    PNAOLOCATIONSERVICE_STATE_AVAILABLE
} PNAOLOCATIONSERVICE_STATE_T;

// callback : status changes notifications
- (void) onStatusChanged:(PNAOLOCATIONSERVICE_STATE_T) status;

// callback : notifies the client when a new location has been computed
- (void) onLocationChanged:(CLLocation *) location;

- (void)didStartNaoLocationService;
- (void)didFailNaoLocationServiceWithError:(NSString*)error;

@end