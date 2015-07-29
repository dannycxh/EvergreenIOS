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
 * @brief Manages all interactions with TrialPay Evergreen SDK.
 *
 * * Initilize the SDK (app key + user id).
 * * Setup Delegates (events and rewards).
 * * Provide easy access to predefined events (app, game, commerce),
 * * Rewards (availability & show).
 * * Test mode.
 *
 * @see @ref tutorial TrialpayEventsDelegate TrialpayRewardsDelegate
*/

@interface Trialpay : NSObject 

/// Delegate for events.
@property (strong, nonatomic) id<TrialpayEventsDelegate> eventsDelegate;
/// Delegate for rewards.
@property (strong, nonatomic) id<TrialpayRewardsDelegate> rewardsDelegate;

/// Holds a persistent state of TrialPay settings (age, level, gender, payer profile).
@property (strong, nonatomic) TPState *state;
/// Predefined App Events
@property (strong, nonatomic) TPEvent *event;
/// Predefined Game Events
@property (strong, nonatomic) TPGameEvent *game;
/// Predefined Commerce Events
@property (strong, nonatomic) TPCommerceEvent *commerce;

+ (void)setEventsDelegate:(id<TrialpayEventsDelegate>)delegate; 
+ (void)setRewardsDelegate:(id<TrialpayRewardsDelegate>)delegate; 

/*!
    Delegate for Offer Wall close events and Balance update events, See TrialpayEventsDelegate, TrialpayRewardsDelegate.
*/

#pragma mark - Register App

/*!
    @brief Initialize TrialPay with an app key.
    @param appId The app key.
 */
+ (void)initApp:(NSString*)appId;

/*!
 @brief Initialize TrialPay with an app key and user id.
 @param appId The app key.
 @param sid The user id.
 */
+ (void)initApp:(NSString*)appId withSid:(NSString*)sid;

#pragma mark - State

/*!
 * @brief Holds a persistent state of TrialPay settings (age, level, gender, payer profile).
 * @return The object that represents TrialPay state.
 */
///
+ (TPState *)state;

/*!
 * @brief Predefined App Events
 * Use it to simplify the use of app events.
 */
+ (TPEvent *)event;

/*!
 * @brief Predefined Game Events
 * Use it to simplify the use of game events.
 */
+ (TPGameEvent *)game;
/*!
 * @brief Predefined Commerce Events
 * Use it to simplify the use of commerce events.
 */
+ (TPCommerceEvent *)commerce;

#pragma mark - Info
/*!
 * @brief Get the version of the SDK.
 * @return The SDK Version.
 */
+ (NSString*)sdkVersion;

#pragma mark - Setup

/*!
 * @brief Set the SID (user identification).
 *
 * The SID is an unique user id for each device user. 
 * It will be used to uniquely identify your user with Trialpay system for monetization and customer support purposes.
 * If you do not maintain a unique user id, we define one for the user by hashing different device identifiers such
 * as IDFA and the device’s MAC address. Please note that choosing this path will prevent us from sending you server
 * side notifications about your users activities.
 * Therefore, for completion notification, please make sure to initiate the Balance Check.
 * @param sid The user identifier.
*/
+ (void)setSid:(NSString *)sid;

/*!
 * @brief Return the SID (user identification).
 * @return The user identifier.
*/
+ (NSString *)sid;

/*!
 * @brief Retrieve the App key.
 * @return The application key with TrialPay.
 */
+ (NSString *)appId;

/*!
 * @internal
 * @brief Set a custom user ID for use with the AdColony SDK, if you've included the AdColony SDK in your app.
 * @param customUserID The custom user ID to be passed to the AdColony SDK.
*/
+ (void)setAdColonyCustomUserID:(NSString *)customUserID; 

#pragma mark - Events

/*!
    @brief Show rewards if any.
    @return TRUE if UI will open (rewards are available)
 */
+ (void)showRewards;


/*!
  @brief Return the rewards availability.
  @return TRUE if rewards are available.
  */
+ (BOOL)hasRewards;

#pragma mark - Debug

/*!
 * @brief Test mode makes all events to be available and open a simple UI.
 */
+ (void)enableTestMode;

@end
