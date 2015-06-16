//
//  NaoZone.h
//  NAOMicroService
//
//  Created by J.CHOUKI on 06/03/2014.
//  Copyright (c) 2014 Pole Star. All rights reserved.
//


typedef NS_ENUM(NSInteger, NRProximityEnum) {
    NRProximityUnknown = 0,
    NRProximityFar = 1,
    NRProximityNear = 2,
    NRProximityImmediate = 3
};

typedef NS_ENUM(NSInteger, NaoZoneTypeEnum) {
    UnknownZone = 0,
    BeaconZone = 1,
    LocRadiusZone = 2,
    GeofencingZone = 3,
    OtherZone = 4
};

@class BeaconRegion;

@interface NaoZone : NSObject

@property NaoZoneTypeEnum type;
@property (readonly) int identifier;
@property (readonly) NSString *name;
@property NRProximityEnum proximity;

- (id)initWithRegion:(BeaconRegion *)region;
+ (NSString *)proximityString:(NRProximityEnum)type;

@end
