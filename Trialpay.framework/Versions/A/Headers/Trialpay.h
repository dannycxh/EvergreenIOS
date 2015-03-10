//
//  Trialpay.h
//
//  Created by Trialpay Inc.
//  Copyright (c) 2013 TrialPay, Inc. All Rights Reserved.
//

#import <Foundation/Foundation.h>


#import "TrialpayEvent.h"
#import "TPEvent.h"
#import "TPGameEvent.h"
#import "TPCommerceEvent.h"
#import "TPState.h"

@class TPEvent;
@class TPState;

@protocol TrialpayEventsDelegate;
@protocol TrialpayRewardsDelegate;
@class TPCommerceEvent;
@class TPGameEvent;

/*!
     This is the class used to perform all SDK tasks.

     @see <a href="http://help.trialpay.com/mobile/ios-sdk">Integrating the TrialPay SDK into an iOS app</a>
     @see @ref SimpleIntegration
*/

@interface Trialpay : NSObject 

/// Delegate for events.
@property (strong, nonatomic) id<TrialpayEventsDelegate> eventsDelegate;
/// Delegate for rewards.
@property (strong, nonatomic) id<TrialpayRewardsDelegate> rewardsDelegate;

/// TrialPay State.
@property (strong, nonatomic) TPState *state;
/// TrialPay Base Events
@property (strong, nonatomic) TPEvent *event;
/// TrialPay Game Events
@property (strong, nonatomic) TPGameEvent *game;
/// TrialPay Commerce Events
@property (strong, nonatomic) TPCommerceEvent *commerce;

+ (void)setEventsDelegate:(id<TrialpayEventsDelegate>)delegate; 
+ (void)setRewardsDelegate:(id<TrialpayRewardsDelegate>)delegate; 

/*!
    Delegate for Offer Wall close events and Balance update events, See TrialpayEventsDelegate, TrialpayRewardsDelegate.
*/

#pragma mark - Register App

/*!
    Initialize TrialPay with an app id.
    @param appId The app id.
 */
+ (void)initApp:(NSString*)appId;

/*!
 Initialize TrialPay with an app id.
 @param appId The app id.
 @param sid The user id.
 */
+ (void)initApp:(NSString*)appId withSid:(NSString*)sid;

#pragma mark - State

/// TrialPay State.
+ (TPState *)state;
/// TrialPay Base Events
+ (TPEvent *)event;

/// TrialPay Game Events
+ (TPGameEvent *)game;
/// TrialPay Commerce Events
+ (TPCommerceEvent *)commerce;

#pragma mark - Info
/*!
     Get the version of the SDK.
     @return The SDK Version.
 */
+ (NSString*)sdkVersion;

#pragma mark - Setup

/*!
     Set SID (device user identification). The SID is an unique user id for each device user. It will be used to uniquely identify your user with Trialpay system for monetization and customer support purposes.
     If you do not maintain a unique user id, we define one for the user by hashing different device identifiers such as IDFA and the device’s MAC address. Please note that choosing this path will prevent us from sending you server side notifications about your users activities.
     Therefore, for completion notification, please make sure to initiate the Balance Check.
    @param sid The device user identifier.
*/
+ (void)setSid:(NSString *)sid;

/*!
     Retrieve the SID (device user identification).
    @return The device user identifier.
*/
+ (NSString *)sid;

/*!
 Retrieve the App ID.
 @return The application ID with TrialPay.
 */
+ (NSString *)appId;

/*!
  Set a custom user ID for use with the AdColony SDK, if you've included the AdColony SDK in your app.
  @param customUserID The custom user ID to be passed to the AdColony SDK.
*/
+ (void)setAdColonyCustomUserID:(NSString *)customUserID;

#pragma mark - Events

/*!
    Show rewards if any.
    @param info Event info for the rewards event (optional)
    @return TRUE if UI will open (rewards are available)
 */
+ (BOOL)showRewards:(NSDictionary *)info;


/*!
  Return the rewards availability.
  @param info Event info for the rewards event (optional)
  @return TRUE if rewards are available.
  */
+ (BOOL)hasRewards:(NSDictionary *)info;

#pragma mark - Debug

/*!
 * Test mode makes all events to be available and open a simple UI.
 */
+ (void)enableTestMode;

@end
