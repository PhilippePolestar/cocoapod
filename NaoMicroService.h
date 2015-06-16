//
//  NaoMicroService.h
//  NaoMicroService
//
//  Created by J.CHOUKI on 19/03/14.
//  Copyright (c) 2014 Pole Star. All rights reserved.
//

#import "PNaoMicroServiceDelegate.h"

@interface NaoMicroService : NSObject

//registering
- (void)registerClient:(id<PNaoMicroServiceDelegate>)client withAppKey:(NSString *)appKey;
- (void)unregisterClient;

// ALERT MANAGEMENT
- (NSMutableArray *)getAlerts;
- (void)watchForAlerts:(NSMutableArray *)alerts;
- (void)stopWatchingForAlerts:(NSMutableArray *)alerts;
- (void)stopWatchingForAllAlerts;
- (void)watchForAllAlerts;
- (NSMutableArray *)getWatchingAlerts;

// REGION MANAGEMENT
- (NSMutableArray*)getNaoZonesOrderedBy:(NSString *)order;

@end