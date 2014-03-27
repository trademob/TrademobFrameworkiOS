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
  mask = (TMTrackingFeatureMaskMAC|
          TMTrackingFeatureMaskWifiSSID|
          TMTrackingFeatureMaskCarrier);
  
  // Set mask
  [TMTracker setTrackingFeatureMask:mask];
  
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
