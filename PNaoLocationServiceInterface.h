//
//  PNaoLocationService.h
//  NaoLocationService
//
//  This protocol is equivalent to INaoLocationService.aidl present for the Android platform.
//  It defines an interface from the application to the service.
//
//  Created by Stéphane Terrenoir on 20/08/10.
//  Copyright Pole Star SA 2010. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "PNaoLocationListenerInterface.h"

// This enum defines the possible errors that prevent the the NaoLocationService from providing location updates.
// MAKE SURE you implement a default to your switch case, as values may be added in the future. New values will be added just before "PNAOLOCATIONSERVICE_ERRORS_UNKNOWN".
// The comment after each value indicates the expected typical message given to the user in order to allow the service to work again correctly.
// Note that the "UNSUPPORTED" values can be guessed also by calling doesDeviceSupportIndoorLocation.
typedef enum PNAOLOCATIONSERVICE_ERRORS_STATUS_ENUM {
    PNAOLOCATIONSERVICE_ERRORS_NONE = 0,
	PNAOLOCATIONSERVICE_ERRORS_UNSUPPORTED_HARDWARE, // Sorry, your phone does not allow you to be located.
	PNAOLOCATIONSERVICE_ERRORS_UNSUPPORTED_OS, // Sorry, your version of iOS does not allow you to be located; please try and upgrade to a newer version.
    PNAOLOCATIONSERVICE_ERRORS_BLUETOOTH_OFF, // Please turn Bluetooth On.

    PNAOLOCATIONSERVICE_ERRORS_WIFI_NOT_CONNECTED, // Please connect to the Wi-Fi network <string you get from getLastError>
    PNAOLOCATIONSERVICE_ERRORS_UNREGISTERED_NETWORK, // You are connected to a network that does not allow indoor location;
													 // please connect to the Wi-Fi network <string you get from getLastError>
    PNAOLOCATIONSERVICE_ERRORS_DATABASE_INITIALISATION,
    PNAOLOCATIONSERVICE_ERRORS_CL_OFF, // Please accept CoreLocation.
    PNAOLOCATIONSERVICE_ERRORS_UNKNOWN // You are no longer located.
} PNAOLOCATIONSERVICE_ERRORS_STATUS;



@protocol PNaoLocationServiceInterface <NSObject>
#pragma mark -
#pragma mark REGISTER CLIENT
// register an application as a client
// the client object must conform to the PNaoLocationListenerInterface protocol
// there can be only one client for each instance of NaoLocationService
- (void) registerClient:(id<PNaoLocationListenerInterface>)client withKey:(NSString *)key;

//register with pdb path name
//pdbPathName is a full path to the nao pdb file that will be used by NaoLocationService
//example pdbPathName : ({location of cache files}/pdb.jscx)
- (void) registerClient:(id<PNaoLocationListenerInterface>)client withKey:(NSString *)key andPdb:(NSString *) pdbPathName;

// unregister the client
- (void) unregisterClient:(id<PNaoLocationListenerInterface>)client;

#pragma mark -
#pragma mark IMPROVE ACCURACY
// Warning:  Do not use these two interfaces
- (void) setPreferedStepLengthMeters:(double) stepLen;
- (void) forceManualLocation:(CLLocation *) location withType:(int)locationType;

#pragma mark -
#pragma mark SOFTWARE INFORMATION
// Returns a string with all needed revision/version info, in a humanly readable format
- (NSString *) getSoftwareVersion;
// Returns a string with all needed database revision/version info, in a humanly readable format
- (NSString *) getDatabaseVersion;
// Returns YES if the current device is compatible with this version of NAO, or NO if not compatible or undetermined.
- (BOOL) doesDeviceSupportIndoorLocation;

#pragma mark -
#pragma mark ERRORS INFORMATION
// get last error when onStatusChanged is notified with errors status
// errorId: error status from Enumerator PNAOLOCATIONSERVICE_ERRORS_STATUS
//err: current err string
- (PNAOLOCATIONSERVICE_ERRORS_STATUS) getLastError:(NSMutableString *) err;


#pragma mark -
#pragma mark POWER REQUIREMENT
//set power requirement: optimize power consumption
//POWER_HIGH (3)
//POWER_MEDUIM (2)
//POWER_LOW (1)
- (void) setPowerRequirement:(int) power;


@end

