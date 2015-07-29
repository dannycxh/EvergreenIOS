//
// Created by Daniel Togni on 8/7/14.
// Copyright (c) 2014 TrialPay Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TrialpayConstants.h"

@class TrialpayEvent;

/*!
 * @brief Predefined Commerce Events.
 *
 * Provides a list of predefined events for commerce, which simplify the use of events.
 * @see @ref predefEvents
 */
@interface TPCommerceEvent : NSObject {}

/// Payer profile (non-payer, payer, whale)
@property (assign, nonatomic) TPPayerProfile payerProfile;

/*!
 * @brief Content Opened.
 * @param contentName Name of the content
 * @param isFirstTime Indicate if this is first time
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventContentOpened:(NSString *)contentName isFirstTime:(NSNumber*)isFirstTime;

/*!
 * @brief Content Closed.
 * @param contentName Name of the content
 * @param isFirstTime Indicate if this is first time
 * @param duration Duration.
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventContentClosed:(NSString *)contentName isFirstTime:(NSNumber *)isFirstTime duration:(NSNumber *)duration;

/*!
 * @brief In-App Purchase Failed.
 * @param currencyName The currency used on the transaction.
 * @param amount The amount of the transaction.
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventIAPFailed:(NSString *)currencyName amount:(NSNumber *)amount;

/*!
 * @brief Store Opened.
 * @param levelId Level.
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventStoreOpened:(NSNumber *)levelId;

/*!
 * @brief Purchase Successful.
 * @param levelId Level.
 * @param itemName The item.
 * @param amount The amount of the transaction.
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventStorePurchaseSuccess:(NSNumber *)levelId itemName:(NSString *)itemName amount:(NSNumber *)amount;

/*!
 * @brief Store Abandoned.
 * @param levelId Level.
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventStorePurchaseAbandoned:(NSNumber *)levelId;

@end
