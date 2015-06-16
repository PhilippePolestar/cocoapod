//
//  NaoMicroServiceDelegate.h
//  NAOMicro
//
//  Created by J.CHOUKI on 06/03/2014.
//  Copyright (c) 2014 Pole Star. All rights reserved.
//

#import "NaoAlert.h"
#import "NaoZone.h"

@protocol PNaoMicroServiceDelegate <NSObject>

- (void)didFailWithError:(NSString *)error;
- (void)didStartNaoMicroService;
- (void)didFireNaoAlert:(NaoAlert *)naoAlert;
- (void)didProximityChangeWithZone:(NaoZone *)naoZone;
- (void)didRangeBeaconWithLabel:(NSString *)label andRssi:(int)rssi;

@end
