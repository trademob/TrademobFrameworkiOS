<p align="center"><img src="./Documentation/images/logo.png"></p>

---

## Integrating the framework

#### 1. Clone the project:

	$ git clone https://github.com/trademob/TrademobFramework.git

After cloning the repository with all its dependencies a folder called "TrademobFramework" has been created.

#### 2. Add the SDK to your project

###### Framework depenencies

Add the following frameworks to your project. Note that if you are targeting iOS versions < 5.0 the AdSupport.framework needs to be optional.

![ ](Documentation/images/frameworks.png)

###### Trademob framework

Open the TrademobFramework/Framework folder and drag the Tradmob.framework folder to an appropriate group in your project. In the example below it was just added on top of all other frameworks the project uses.

![ ](Documentation/images/trademobFramework.png)

#### 3. Add tracking code

###### File: Prefix.pch

Add the TMTracker header to your prefix file. For a freshly setup project you prefix file should look similar to the example:

```
#ifdef __OBJC__
  #import <UIKit/UIKit.h>
  #import <Foundation/Foundation.h>
  #import <Trademob/TMTracker.h>
#endif
```

###### File: AppDelegate

* Add [TMTracker start] to the -(BOOL)application:didFinishLaunchingWithOptions method
* Configure tracking options if desired
* You are ready to go

```
- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
  // Display window
  [self.window makeKeyAndVisible];
  
  // Invoke Trademob tracker
  [TMTracker start];
  
  // Application start succeeded
  return YES;
}

```

#### 4. Options

Certain tracking features can be disabled via feature mask. See the list below for possible options.

Flag                               | Description
-----------------------------------|--------------------------------------------------
TMTrackingFeatureMaskNone          | enables all features (this is the default value)
TMTrackingFeatureMaskIDFA          | disables IDFA tracking
TMTrackingFeatureMaskMAC           | disables  MAC Adress tracking
TMTrackingFeatureMaskWifiSSID      | disables WIFISSID tracking
TMTrackingFeatureMaskCarrier       | disables phone carrier tracking
TMTrackingFeatureMaskInstalledApps | disables tracking of installed apps

Values can be combined using bitwise inclusive OR.
Example: To disable all features mentioned above combine the values like so:

```
  // Create tracking feature mask
  TMTrackingFeatureMask mask;
  mask = (TMTrackingFeatureMaskIDFA|
          TMTrackingFeatureMaskMAC|
          TMTrackingFeatureMaskWifiSSID|
          TMTrackingFeatureMaskCarrier|
          TMTrackingFeatureMaskInstalledApps);
  
  // Set mask
  [TMTracker setTrackingFeatureMask:mask];
```

#### 5. Custom tracking

Tracking happens completely automatic but if desired special events can be tracked by the developer using custom tracking events. A custom tracking event is beeing composed of an event key and an optional info value.

```
NSString *key = @"OldKingCole";
NSDictionary *value = @{@"HeCalledForHis": @[@"PipeAndBowl"]};
[TMTracker track:key info:value];
```

#### 6. Demo app

The demo app features a simple project readily setup for Trademob tracking.

#### 7. Requirements

* Minimum iOS version: 4.1.
* Framework size: 517kb