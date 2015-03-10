//
// Created by Daniel Togni on 7/30/14.
// Copyright (c) 2014 TrialPay Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TrialpayEvent.h"

/*!
 Base event class.
 Performs events tasks and provides external API methods.

 @see @ref SimpleIntegration
 */
@interface TPEvent : TrialpayEvent {

}

// Event creation

/*!
 * Create an app loaded event.
 * @param timeSinceLast the time since last event
 * @return A TrialpayEvent.
 */
- (TrialpayEvent *)eventAppLoaded:(NSNumber*)timeSinceLast;

/*!
 * Create an app resumed event.
 * @param timeSinceLast the time since last event
 * @return A TrialpayEvent.
 */
- (TrialpayEvent *)eventAppResumed:(NSNumber*)timeSinceLast;

// User

/*!
 * Create an user sign up event.
 * @param isKnownUser A boolean to determine if this is an existing user.
 * @return A TrialpayEvent.
 */
- (TrialpayEvent *)eventUserSignUp:(NSNumber*)isKnownUser;
/*!
 * Create an user sign in event.
 * @param timeSinceLast the time since last event
 * @return A TrialpayEvent.
 */
- (TrialpayEvent *)eventUserSignIn:(NSNumber*)timeSinceLast;

/*!
 * Create a menu opened event.
 * @param menuId the id of the menu
 * @return A TrialpayEvent.
 */
- (TrialpayEvent *)eventMenuOpened:(NSNumber*)menuId;
/*!
 * Create a menu closed event.
 * @param menuId the id of the menu
 * @return A TrialpayEvent.
 */
- (TrialpayEvent *)eventMenuClosed:(NSNumber*)menuId;

/*!
 * Create an item gained event.
 * @param levelId The id of the item
 * @param itemName the name of the item
 * @param amount the quantity of items
 * @return A TrialpayEvent.
 */
- (TrialpayEvent *)eventItemGained:(NSNumber *)levelId itemName:(NSString *)itemName amount:(NSNumber *)amount;
/*!
 * Create an item used event.
 * @param level_id The id of the item
 * @param itemName the name of the item
 * @param amount the quantity of items
 * @return A TrialpayEvent.
 */
- (TrialpayEvent *)eventItemUsed:(NSNumber *)level_id itemName:(NSString *)itemName amount:(NSNumber *)amount;

/*!
 * Create a show UI event.
 * @param name the UI name
 * @return A TrialpayEvent.
 */
- (TrialpayEvent *)eventShowUI:(NSString*)name;
/*!
 * Create a hide UI event.
 * @param name the UI name
 * @return A TrialpayEvent.
 */
- (TrialpayEvent *)eventHideUI:(NSString*)name;

/*!
 * Create a button click event.
 * @param buttonName the button name.
 * @return A TrialpayEvent.
 */
- (TrialpayEvent *)eventButtonClicked:(NSString *)buttonName;

@end
