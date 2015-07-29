//
// Created by Daniel Togni on 7/30/14.
// Copyright (c) 2014 TrialPay Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TrialpayEvent.h"

/*!
 * @brief Predefined App Events.
 *
 * Provides a list of predefined events for apps, which simplify the use of events.
 * @see predefEvents
 */
@interface TPEvent : TrialpayEvent {

}

#pragma mark - Event creation

/*!
 * @brief Create an app loaded event.
 * @param timeSinceLast the time since last event
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventAppLoaded:(NSNumber*)timeSinceLast;

/*!
 * @brief Create an app resumed event.
 * @param timeSinceLast the time since last event
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventAppResumed:(NSNumber*)timeSinceLast;

// User

/*!
 * @brief Create an user sign up event.
 * @param isKnownUser A boolean to determine if this is an existing user.
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventUserSignUp:(NSNumber*)isKnownUser;
/*!
 * @brief Create an user sign in event.
 * @param timeSinceLast the time since last event
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventUserSignIn:(NSNumber*)timeSinceLast;

/*!
 * @brief Create a menu opened event.
 * @param menuId the id of the menu
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventMenuOpened:(NSNumber*)menuId;
/*!
 * @brief Create a menu closed event.
 * @param menuId the id of the menu
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventMenuClosed:(NSNumber*)menuId;

/*!
 * @brief Create an item gained event.
 * @param levelId The id of the item
 * @param itemName the name of the item
 * @param amount the quantity of items
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventItemGained:(NSNumber *)levelId itemName:(NSString *)itemName amount:(NSNumber *)amount;
/*!
 * @brief Create an item used event.
 * @param level_id The id of the item
 * @param itemName the name of the item
 * @param amount the quantity of items
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventItemUsed:(NSNumber *)level_id itemName:(NSString *)itemName amount:(NSNumber *)amount;

/*!
 * @brief Create a show UI event.
 * @param name the UI name
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventShowUI:(NSString*)name;
/*!
 * @brief Create a hide UI event.
 * @param name the UI name
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventHideUI:(NSString*)name;

/*!
 * @brief Create a button click event.
 * @param buttonName the button name.
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventButtonClicked:(NSString *)buttonName;

/*!
 * @brief Creates an event for low balance if a required amount is not fulfilled.
 * @param currencyName the currency to receive the balance
 * @param amount the current balance
 * @param requiredAmount the minimum balance required
 * @return The event created if the minimum was not reached.
 */
- (TrialpayEvent *)eventLowBalance:(NSString *)currencyName currentAmount:(NSNumber *)amount requiredAmount:(NSNumber *)requiredAmount;

@end
