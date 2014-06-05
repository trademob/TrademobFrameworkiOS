//  Copyright 2014 Trademob. All rights reserved.

// Apple
#import <Foundation/Foundation.h>

/**
 * Defines methods for:
 *
 * * invoking tracking
 * * diable tracking
 * * set tracking fatures
 * * track custom events
 */

// Tracking feature flags
typedef NS_OPTIONS(NSUInteger,TMTrackingFeatureMask) {
  TMTrackingFeatureMaskNone          = 0,
	TMTrackingFeatureMaskMAC           = 1 << 0,
	TMTrackingFeatureMaskWifiSSID      = 1 << 1,
	TMTrackingFeatureMaskCarrier       = 1 << 2,
	TMTrackingFeatureMaskInstalledApps = 1 << 3
};

@protocol TMTrackerAPI

# pragma mark - Tracking

/**
 * Initializes the shared instance of TMTracker.
 * Errors are beeing logged to the console.
 * Neither is the singleton instance itself beeing returned at any point nor
 * is it accessible in any way.
 * @return Returns NO if there was an error during initialization. Returns YES otherwise.
 */

+ (BOOL)start;

/**
 * This method call must be placed in the class that implements the UIApplicationDelegate
 * method -application:openURL:sourceApplication:annotation:
 * It forwards the URL the app was opened with to the tracker for usage
 * in tracking events. While no tracking is beeing triggered directly
 * by using this method, the provided URL will be used by the next appropriate
 * tracking event. The sample code shows the proper integration of this method.
 *
 *
 *	- (BOOL)application:(UIApplication *)application
 *	            openURL:(NSURL *)url
 *	  sourceApplication:(NSString *)sourceApplication
 *	         annotation:(id)annotation
 *	{
 *	  [TMTracker trackOpenURL:url];
 *	  return YES;
 *	}
 *
 * @param url The NSURL supplied via method argument
 * @warning Calling of this method is required! 
 * If it is missing tracking of app open URLs does not work properly!
 */

+ (void)setOpenURL:(NSURL *)url;

/**
 * Sends a custom tracking event to the server.
 * A custom event is composed of a event key and an optional info value.
 * @param event A NSString used as key for the event. This value may not be nil.
 * @param info A NSDictionary used as the value for the event. This value may be nil.
 */

+ (void)track:(NSString *)event info:(NSDictionary *)info;

/**
 * Fetches payload data containing campaign information
 * tailored to the app context that the app was installed from.
 * If the request completes successfully and context data is available, 
 * the context parameter of the handler block contains the appropriate data, 
 * and the error parameter is nil. 
 * If no context data is available the context parameter of the handler block is nil
 * and the error parameter is nil. 
 * If the request fails, the data parameter is nil 
 * and the error parameter contain information about the failure.
 */

+ (void)clickContextCompletionHandler:
  (void (^)(NSDictionary *context, NSError *error))block;

# pragma mark - Features

/**
 * Sets the feature mask based on which individual tracking features are beeing disabled.
 * If a feature is mentioned in the mask ("masked") it is beeing disabled.
 *
 * Possible values are:
 *
 * Flag                               | Description
 * -----------------------------------|--------------------------------------------------
 * TMTrackingFeatureMaskNone          | enables all features (this is the default value)
 * TMTrackingFeatureMaskMAC           | disables  MAC Adress tracking
 * TMTrackingFeatureMaskWifiSSID      | disables WIFISSID tracking
 * TMTrackingFeatureMaskCarrier       | disables phone carrier tracking
 * TMTrackingFeatureMaskInstalledApps | disables tracking of installed apps
 *
 * Values can be combined using bitwise inclusive OR.
 *
 * Example: To disbale all features mentioned above combine the values like so:
 *
 * (TMTrackingFeatureMaskMAC|TMTrackingFeatureMaskWifiSSID|
 * TMTrackingFeatureMaskCarrier|TMTrackingFeatureMaskInstalledApps)
 * @param mask TMTrackingFeatureMask
 */

+ (void)setTrackingFeatureMask:(TMTrackingFeatureMask)mask;

/**
 * Activates tracking. Tracking is activated by default.
 * Only use this methid to reactivate tracking after it has been
 * deactivated using disable
 */

+ (void)enable;

/**
 * Deactivates tracking. This is a persistent operation.
 * If tracking has been deactivated using this method no tracking
 * will be performed at all, even after app restarts.
 * Tracking will only be performed again when the enable method
 * has been called before invoking start
 */

+ (void)disable;

@end
