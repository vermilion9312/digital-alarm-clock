/*
 * stopwatch_mode.c
 *
 *  Created on: Sep 1, 2026
 *      Author: LeeJooHo
 */


#include <stopwatch_mode.h>

static void StopwatchMode_EnterState(StopwatchMode* this, StopwatchState nextState)
{
	if (this->state == nextState) return;
	this->state = nextState;

	switch (nextState)
	{
	case STOPWATCH_STOPPED:
		Counter_SetRunning(this->counter, false);
		Counter_ResetCount(this->counter);
		break;

	case STOPWATCH_RUNNING:
		Counter_SetRunning(this->counter, true);
		break;

	case STOPWATCH_PAUSED:
		Counter_SetRunning(this->counter, false);
		break;

	default:
		break;
	}
}

void StopwatchMode_Init(StopwatchMode* this, Input* stateButton, Input* resetButton, Counter* counter)
{
	this->stateButton = stateButton;
	this->resetButton = resetButton;

	this->counter = counter;

	this->state = STOPWATCH_STOPPED;
}

void StopwatchMode_Update(StopwatchMode* this)
{
	switch (this->state)
	{
	case STOPWATCH_STOPPED:
		if (Input_IsRisingEdge(this->stateButton))
		{
			StopwatchMode_EnterState(this, STOPWATCH_RUNNING);
		}
		break;

	case STOPWATCH_RUNNING:
		if (Input_IsRisingEdge(this->stateButton))
		{
			StopwatchMode_EnterState(this, STOPWATCH_PAUSED);
		}
		break;

	case STOPWATCH_PAUSED:
		if (Input_IsRisingEdge(this->resetButton))
		{
			StopwatchMode_EnterState(this, STOPWATCH_STOPPED);
		}
		else if (Input_IsRisingEdge(this->stateButton))
		{
			StopwatchMode_EnterState(this, STOPWATCH_RUNNING);
		}
		break;

	default:
		break;
	}

	Segment_Update(Counter_GetCount(this->counter));
}
