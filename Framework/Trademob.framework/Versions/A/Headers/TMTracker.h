// Apple
#import <Foundation/Foundation.h>

// Framework protocols
#import "TMTrackerAPI.h"

/**
 * TMTracker is the single entry point in order to invoke the tracking via TrademobSDK.
 * It exposes the absolute minumum of methods in order to do so.
 * Task performed by TMTracker are:
 *
 * * initializing the TMTracker singleton
 * * enabling/disabling tracking features
 * * tracking a custom event
 */

@interface TMTracker : NSObject <TMTrackerAPI>

@end
