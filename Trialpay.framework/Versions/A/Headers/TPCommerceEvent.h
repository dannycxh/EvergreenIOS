//
// Created by Daniel Togni on 8/7/14.
// Copyright (c) 2014 TrialPay Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TrialpayConstants.h"

@class TrialpayEvent;

/*!
 Commerce event class.
 Provides external API methods.

 @see @ref AppCode
 */
@interface TPCommerceEvent : NSObject {}

@property (assign, nonatomic) TPPayerProfile payerProfile;

/*!
 * event
 */
- (TrialpayEvent *)eventContentOpened:(NSString *)contentName isFirstTime:(NSNumber*)isFirstTime;
/*!
 * event
 */
- (TrialpayEvent *)eventContentClosed:(NSString *)contentName isFirstTime:(NSNumber *)isFirstTime duration:(NSNumber *)duration;

/*!
 * event
 */
- (TrialpayEvent *)eventIAPFailed:(NSString *)currencyName amount:(NSNumber *)amount;

/*!
 * event
 */
- (TrialpayEvent *)eventStoreOpened:(NSNumber *)levelId;
/*!
 * event
 */
- (TrialpayEvent *)eventStorePurchaseSuccess:(NSNumber *)levelId itemName:(NSString *)itemName amount:(NSNumber *)amount;
/*!
 * event
 */
- (TrialpayEvent *)eventStorePurchaseAbandoned:(NSNumber *)levelId;

@end
