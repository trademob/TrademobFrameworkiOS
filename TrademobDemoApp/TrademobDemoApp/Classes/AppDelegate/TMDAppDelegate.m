// Header
#import "TMDAppDelegate.h"

@implementation TMDAppDelegate

# pragma mark - <UIApplicationDelegate>

- (BOOL)application:(UIApplication *)application
  didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  // Display window
  [self.window makeKeyAndVisible];
  
  // Invoke Trademob tracker
  [TMTracker start];
  
  // Create tracking feature mask
  TMTrackingFeatureMask mask;
  mask = (TMTrackingFeatureMaskIDFA|
          TMTrackingFeatureMaskMAC|
          TMTrackingFeatureMaskWifiSSID|
          TMTrackingFeatureMaskCarrier);
  
  // Set mask
  [TMTracker setTrackingFeatureMask:mask];
  
  // Custom tracking sample
  // Generate an action info hash that contains any domain-specific key-value
  // pairs and an integer typed value
  NSDictionary *info = @{@"user_id": @"anywho",
                         @"stuff_id": @"anywhat",
                         @"value": @1299};
  
  // Call the Trademob Tracker singleton to track the action and its info hash
  [TMTracker track:@"foobar_action" info:info];
  
  // Application start succeeded
  return YES;
}

- (BOOL)application:(UIApplication *)application
            openURL:(NSURL *)url
  sourceApplication:(NSString *)sourceApplication
         annotation:(id)annotation
{
  // Store open URL
  [TMTracker setOpenURL:url];
  
  return YES;
}

@end
