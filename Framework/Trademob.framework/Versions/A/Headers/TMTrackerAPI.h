// Apple
#import <Foundation/Foundation.h>

// Tracking feature flags
typedef NS_OPTIONS(NSUInteger,TMTrackingFeatureMask) {
  TMTrackingFeatureMaskNone          = 0,
	TMTrackingFeatureMaskIDFA          = 1 << 0,
	TMTrackingFeatureMaskMAC           = 1 << 1,
	TMTrackingFeatureMaskWifiSSID      = 1 << 2,
	TMTrackingFeatureMaskCarrier       = 1 << 3,
	TMTrackingFeatureMaskInstalledApps = 1 << 4
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
 * Sends a custom tracking event to the server.
 * A custom event is composed of a event key and an optional info value.
 * @param event A NSString used as key for the event. This value may not be nil.
 * @param info A NSDictionary used as the value for the event. This value may be nil.
 */

+ (void)track:(NSString *)event info:(NSDictionary *)info;

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
 * TMTrackingFeatureMaskIDFA          | disables IDFA tracking
 * TMTrackingFeatureMaskMAC           | disables  MAC Adress tracking
 * TMTrackingFeatureMaskWifiSSID      | disables WIFISSID tracking
 * TMTrackingFeatureMaskCarrier       | disables phone carrier tracking
 * TMTrackingFeatureMaskInstalledApps | disables tracking of installed apps
 *
 * Values can be combined using bitwise inclusive OR.
 *
 * Example: To disbale all features mentioned above combine the values like so:
 *
 * (TMTrackingFeatureMaskIDFA|TMTrackingFeatureMaskMAC|TMTrackingFeatureMaskWifiSSID|
 * TMTrackingFeatureMaskCarrier|TMTrackingFeatureMaskInstalledApps)
 * @param mask TMTrackingFeatureMask
 */

+ (void)setTrackingFeatureMask:(TMTrackingFeatureMask)mask;

/**
 * Activates tracking. Tracking is activated by default.
 * Only use this methid to reactivate tracking after it has been
 * deactivated using -(void)deactivate.
 */

+ (void)activate;

/**
 * Dectivates tracking. This is a persistent operation.
 * If tracking has been daactivated using this method no tracking
 * will be performed at all, even after app restarts.
 * Tracking will only be performed again when the -(void)activate method
 * has been called.
 */

+ (void)deactivate;

@end
