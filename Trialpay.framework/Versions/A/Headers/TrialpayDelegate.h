//
// Created by Trialpay, Inc. on 10/24/13.
// Copyright (c) 2013 TrialPay Inc. All rights reserved.
//

#ifndef __TrialpayDelegate_H_
#define __TrialpayDelegate_H_

@class Trialpay;
@class TrialpayEvent;

/*!
     Delegate for Trialpay events.
*/
@protocol TrialpayEventsDelegate
@optional

/*!
     Announces Trialpay view was open.
     @param trialpay the trialpay  object which triggered the event
     @param event the event that triggered the view to open
     @return TRUE if offerwall should open.
*/
- (BOOL)trialpay:(Trialpay *)trialpay shouldOpenForEvent:(TrialpayEvent *)event;

/*!
     Announces Trialpay view was closed.
     @param trialpay the trialpay  object which triggered the event
     @param event the event that triggered the view to open
*/
- (void)trialpay:(Trialpay *)trialpay didCloseForEvent:(TrialpayEvent *)event;


/*!
     Announces Trialpay view was closed.
     @param trialpay the trialpay  object which triggered the event
     @param event the event that triggered the view to open
*/
- (void)trialpay:(Trialpay *)trialpay eventIsUnavailable:(TrialpayEvent *)event;
@end

/*!
 Delegate for TrialPay rewards.
 */
@protocol TrialpayRewardsDelegate
/*!
     Announces that rewards are now available.
     @param trialpay the trialpay  object which triggered the event
     @param amount the amount of credits
     @param currency the currency that should be credited
*/
- (void)trialpay:(Trialpay *)trialpay reward:(int)amount rewardId:(NSString *)rewardId;

@optional

/*!
 Announces that rewards are now available.
 @param trialpay the trialpay  object which triggered the event
 @param rewardInfo information that is exposed related to this rewards
 */
- (void)trialpay:(Trialpay *)trialpay rewardsAreAvailable:(NSDictionary *)rewardInfo;

@end

#endif //__TrialpayDelegate_H_
