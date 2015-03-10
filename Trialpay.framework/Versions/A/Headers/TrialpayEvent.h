//
// Created by Daniel Togni on 11/3/14.
// Copyright (c) 2014 TrialPay Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/*!
 Represents the events on TrialPay SDK.
 */
@interface TrialpayEvent : NSObject {

}

/*! The full name of the event (ex: show_ui_main, button_clicked_offers, game_paused)*/
@property (nonatomic, readonly, copy) NSString *fullName;
/*! The name of the event (ex: show_ui, button_clicked, game_paused) */
@property (nonatomic, copy) NSString *name;
/*! A dictionary with information about this event */
@property (nonatomic, strong) NSDictionary *eventInfo;

/*!
 * Create a custom event.
 * @param name The name of the event.
 * @param info A dictionary with information associated with this event.
 * @return A new event.
 */
- (id)initWithName:(NSString *)name info:(NSDictionary *)info;

/*!
 * Create a custom event.
 * @param eventName name
 * @param info The event info (optional).
 * @return An TrialpayEvent.
 */
+ (TrialpayEvent *)eventWithName:(NSString *)eventName info:(NSDictionary *)info;

/*!
 * Checks if there are offers to be presented.
 * @return Yes if it is available
 */
- (BOOL)isAvailable;

/*!
 * Executes the action assigned for this event.
 */
- (void)fire;

/*!
 * Executes the action assigned for this event, presenting on a given view controller.
 * @param viewController The view controller where the Trialpay UI will be pushed to.
 */
- (void)fireOnViewController:(UIViewController*)viewController;

/*!
 * Get the display information, for creating customized UI for this event.
 * @returns an array with:
 * <ul>
 * <li> button_tile: the title for buttons
 * <li> title:       the title of the offer
 * <li> vc_amount:  virtual currency rewards by this offer
 * <li> image_url:   the URL for the image that represents the offer
 * </ul>
 */
- (NSDictionary *)touchpointInfo;

/*!
 * Fire a pixel to Trialpay letting us know that you've displayed a Trialpay offer via touchpointInfo.
 * This allows us to track and optimize offer performance.
 */
- (void)registerOfferImpression;

- (void)dirtyCache;
@end
