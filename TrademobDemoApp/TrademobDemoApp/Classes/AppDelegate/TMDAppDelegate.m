// Header
#import "TMDAppDelegate.h"

@implementation TMDAppDelegate

# pragma mark - Template methods

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
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
          TMTrackingFeatureMaskCarrier|
          TMTrackingFeatureMaskInstalledApps);
  
  // Set mask
  [TMTracker setTrackingFeatureMask:mask];
  
  // Custom tracking sample
  NSString *key = @"OldKingCole";
  NSDictionary *value = @{@"HeCalledForHis": @[@"PipeandBowl"]};
  [TMTracker track:key info:value];
  
  // Application start succeeded
  return YES;
}

@end
