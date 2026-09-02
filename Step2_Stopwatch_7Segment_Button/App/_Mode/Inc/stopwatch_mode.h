/*
 * stopwatch_mode.h
 *
 *  Created on: Sep 1, 2026
 *      Author: LeeJooHo
 */

#ifndef MODE_INC_STOPWATCH_MODE_H_
#define MODE_INC_STOPWATCH_MODE_H_

#include <input.h>
#include <segment.h>
#include <counter.h>

typedef enum {
	STOPWATCH_STOPPED,
	STOPWATCH_RUNNING,
	STOPWATCH_PAUSED
} StopwatchState;

typedef struct {
	Input* stateButton;
	Input* resetButton;

	Counter* counter;

	StopwatchState state;
} StopwatchMode;

void StopwatchMode_Init(StopwatchMode*, Input*, Input*, Counter*);
void StopwatchMode_Update(StopwatchMode*);

#endif /* MODE_INC_STOPWATCH_MODE_H_ */
