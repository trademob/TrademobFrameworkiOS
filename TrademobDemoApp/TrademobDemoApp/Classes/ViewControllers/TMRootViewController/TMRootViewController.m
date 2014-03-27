// Header
#import "TMRootViewController.h"

@implementation TMRootViewController

#pragma mark - IBActions

- (IBAction)trackCustomAction:(id)sender
{
  // Custom tracking sample
  // Generate an action info hash that contains any domain-specific key-value
  // pairs and an integer typed value
  NSDictionary *info = @{@"user_id": @"anywho",
                         @"stuff_id": @"anywhat",
                         @"value": @1299};
  
  // Call the Trademob Tracker singleton to track the action and its info hash
  [TMTracker track:@"foobar_action" info:info];
}

@end
