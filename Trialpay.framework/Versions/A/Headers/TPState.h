//
// Created by Daniel Togni on 8/6/14.
// Copyright (c) 2014 TrialPay Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TrialpayConstants.h"


@class TPState;
@class TrialpayEvent;

/*!
 * Trialpay State class manages customer related states (ex: age, gender, balance, custom parameters).
 */
@interface TPState : NSObject {
}

/*!
 * Age of the user.
 */
@property (strong, nonatomic) NSNumber *age;
/*!
 * Gender of the user.
 */
@property (assign, nonatomic) TPGender gender;
/*!
 * Current game level.
 */
@property (strong, nonatomic) NSNumber *level;

#pragma mark - Extended API

/*! 
 * Return the balances registered.
 * @return A dictionary with the balances
 */
- (NSDictionary*)balances;

/*!
 * Set a balance.
 * @param amount the amount to be added
 * @param currency the currency to receive the balance
 */
- (void)setBalance:(int)amount forCurrency:(NSString *)currency;

/*!
 * Creates an event for low balance if a required amount is not fulfilled.
 * @param currencyName the currency to receive the balance
 * @param amount the current balance
 * @param requiredAmount the minimum balance required
 * @return The event created if the minimum was not reached.
 */
- (TrialpayEvent *)eventLowBalance:(NSString *)currencyName currentAmount:(NSNumber *)amount requiredAmount:(NSNumber *)requiredAmount;

/*!
    This method stores custom parameters. All set parameters (even if they have a value of an empty string) will be passed on API calls.
    If the value is set to Null, the passed value will be "" (empty string).
    @param value The value of the parameter.
    @param name The name of the parameter.
*/
- (void)setCustomParamValue:(NSString *)value forName:(NSString *)name;

/*!
 * Return the current custom parameters.
 * @return A dictionary with the custom parameters.
 */
- (NSDictionary*)customParams;

@end
