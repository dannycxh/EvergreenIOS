//
// Created by Daniel Togni on 8/7/14.
// Copyright (c) 2014 TrialPay Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TrialpayEvent;

/*!
 * Collection of predefined events for Games
 */
@interface TPGameEvent : NSObject {
}

@property (strong, nonatomic) NSNumber *level;

/*!
 * New game event
 * @param isFirstTime is first time
 */
- (TrialpayEvent *)eventNewGame:(NSNumber*)isFirstTime;
/*!
 * event
 */
- (TrialpayEvent *)eventGameOver:(NSNumber*)isFirstTime;
/*!
 * event
 */
- (TrialpayEvent *)eventGameResumed:(NSNumber*)isFirstTime;
/*!
 * event
 */
- (TrialpayEvent *)eventGamePaused:(NSNumber*)isFirstTime;
/*!
 * event
 */
- (TrialpayEvent *)eventLevelStart:(NSNumber *)levelId restarting:(NSNumber*)isRestarting;
/*!
 * event
 */
- (TrialpayEvent *)eventLevelEnd:(NSNumber *)levelId success:(NSNumber *)success fail:(NSNumber *)fail isFirstTime:(NSNumber *)isFirstTime duration:(NSNumber *)duration score:(NSNumber *)score scoreRank:(NSNumber*)scoreRank;
/*!
 * event
 */
- (TrialpayEvent *)eventTutorialStart:(NSNumber *)tutorialId isFirstTime:(NSNumber*)isFirstTime;
/*!
 * event
 */
- (TrialpayEvent *)eventTutorialEnd:(NSNumber*)tutorialId;
/*!
 * event
 */
- (TrialpayEvent *)eventExperienceUpdate:(NSNumber*)amount;

@end
