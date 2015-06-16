//
//  NAOAlert.h
//  NAOMicroService
//
//  Created by J.CHOUKI on 06/03/2014.
//  Copyright (c) 2014 Pole Star. All rights reserved.
//

@class Beacon;

@interface NaoAlert : NSObject

@property (nonatomic) BOOL activated;

@property (readonly) int identifier;
@property (readonly) NSString *name;
@property (readonly) NSString *content;
@property (nonatomic, assign) BOOL analytics;

- (id)initWithIdentifer:(int)identifier andName:(NSString *)name andContent:(NSString *)content andRules:(NSArray *)rules andStartTime:(NSDate*)sTime andEndTime:(NSDate*)eTime;

+ (int)getTempId;
- (void)onEvent:(id)e;
- (BOOL)check;
- (NSMutableArray *)getConcernedRegions;
- (void)resetAllRules;
+ (NSMutableArray *)getList;
+ (NSArray *)regionsOfAllActiveAlerts;
+ (Beacon *)findBeaconOfActiveAlertsByBabid:(int)babid;
- (BOOL)isTypeOf:(NSString *)type;


@end