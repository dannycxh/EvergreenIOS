//
// Created by Daniel Togni on 11/3/14.
// Copyright (c) 2014 TrialPay Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*!
 * @brief The event object.
 * 
 * Provides the core event functionality.
 *
 * @see @ref events
 */
@interface TrialpayEvent : NSObject {

}

/// The full name of the event (ex: show_ui_main, button_clicked_offers, game_paused)
@property (nonatomic, readonly, copy) NSString *fullName;
/// The name of the event (ex: show_ui, button_clicked, game_paused)
@property (nonatomic, copy) NSString *name;
/// A dictionary with information about this event
@property (nonatomic, strong) NSDictionary *eventInfo;

/*!
 * @brief Create a custom event.
 * @param name The name of the event.
 * @param info A dictionary with information associated with this event.
 * @return A new event.
 */
- (id)initWithName:(NSString *)name info:(NSDictionary *)info;

/*!
 * @brief Create a custom event.
 * @param eventName name
 * @param info The event info (optional).
 * @return An TrialpayEvent.
 */
+ (TrialpayEvent *)eventWithName:(NSString *)eventName info:(NSDictionary *)info;

/*!
 * @brief Checks if there are offers available for this event.
 * @return YES if there are offers available
 */
- (void)isAvailable:(void (^)(BOOL isAvailable))block;

/*!
 * @brief Executes the action assigned for this event.
 */
- (void)fire;

/*!
 * @brief Executes the action assigned for this event, presenting on a given view controller.
 * @param viewController The view controller where the TrialPay UI will be pushed to.
 */
- (void)fireOnViewController:(UIViewController*)viewController;

/*!
 * @brief Get the native offer information for creating customized UI for this event.
 * @see @ref nativeOffers
 * @returns an array with the Native Offers data.
 */
- (NSDictionary *)touchpointInfo;

/*!
 * @brief Fire a pixel to Trialpay letting us know that you've displayed a Trialpay offer via touchpointInfo.
 *
 * This allows us to track and optimize offer performance.
 */
- (void)registerOfferImpression;

@end
