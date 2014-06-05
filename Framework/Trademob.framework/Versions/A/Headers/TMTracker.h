//  Copyright 2014 Trademob. All rights reserved.

// Apple
#import <Foundation/Foundation.h>

// Framework protocols
#import "TMTrackerAPI.h"

/**
 * TMTracker is the single entry point in order to invoke tracking.
 * The TMTrackerAPI protocol exposes all necessary methods.
 */

@interface TMTracker : NSObject <TMTrackerAPI>

@end
