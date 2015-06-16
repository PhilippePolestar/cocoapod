//
//  NaoLocationServiceInterface.h
//  NaoLocationServiceInterface
//
//	Main class of the NaoLocationService library
//
//  Created by Stéphane Terrenoir on 20/08/10.
//  Copyright Pole Star SA 2010. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "PNaoLocationServiceInterface.h"
#import "PNaoLocationListenerInterface.h"


@interface NaoLocationServiceInterface : NSObject <PNaoLocationServiceInterface>

@property (nonatomic, retain) id myObject;

@end
