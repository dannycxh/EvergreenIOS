//
// Created by Daniel Togni on 8/7/14.
// Copyright (c) 2014 TrialPay Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TrialpayEvent;

/*!
 * @brief Predefined Game Events.
 *
 * Provides a list of predefined events for games, which simplify the use of events.
 * @see @ref predefEvents
 */
@interface TPGameEvent : NSObject {
}

/// User level in the game.
@property (strong, nonatomic) NSNumber *level;

/*!
 * @brief New Game.
 * @param isFirstTime is first time
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventNewGame:(NSNumber*)isFirstTime;
/*!
 * @brief Game Over.
 * @param isFirstTime is first time
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventGameOver:(NSNumber*)isFirstTime;
/*!
 * @brief Game Resumed.
 * @param isFirstTime is first time
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventGameResumed:(NSNumber*)isFirstTime;
/*!
 * @brief Game Paused.
 * @param isFirstTime is first time
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventGamePaused:(NSNumber*)isFirstTime;
/*!
 * @brief Level Start.
 * @param levelId Level.
 * @param isRestarting is restarting the level
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventLevelStart:(NSNumber *)levelId restarting:(NSNumber*)isRestarting;
/*!
 * @brief Level End.
 * @param levelId Level.
 * @param success Success.
 * @param fail Fail.
 * @param isFirstTime is first time
 * @param duration duration
 * @param score score
 * @param scoreRank score rank.
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventLevelEnd:(NSNumber *)levelId success:(NSNumber *)success fail:(NSNumber *)fail isFirstTime:(NSNumber *)isFirstTime duration:(NSNumber *)duration score:(NSNumber *)score scoreRank:(NSNumber*)scoreRank;
/*!
 * @brief Tutorial Start.
 * @param tutorialId Tutorial id.
 * @param isFirstTime is first time
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventTutorialStart:(NSNumber *)tutorialId isFirstTime:(NSNumber*)isFirstTime;
/*!
 * @brief Tutorial End.
 * @param tutorialId Tutorial id.
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventTutorialEnd:(NSNumber*)tutorialId;
/*!
 * @brief Experience Update.
 * @param amount The amount of experience (delta).
 * @return An object representing the event.
 */
- (TrialpayEvent *)eventExperienceUpdate:(NSNumber*)amount;

@end
