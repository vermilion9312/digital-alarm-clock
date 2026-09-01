/*
 * stopwatch_mode.c
 *
 *  Created on: Sep 1, 2026
 *      Author: LeeJooHo
 */


#include <stopwatch_mode.h>

static void StopwatchMode_SetState(StopwatchMode* this, StopwatchState state)
{
	this->state = state;
}

void StopwatchMode_Init(StopwatchMode* this, Input* stateButton, Input* resetButton, Segment* segment)
{
	this->stateButton = stateButton;
	this->resetButton = resetButton;

	this->segment = segment;
}

void StopwatchMode_Update(StopwatchMode* this)
{
	switch (this->state)
	{
	case STOPWATCH_STOPPED:
		if (Input_IsRisingEdge(this->stateButton))
		{
			StopwatchMode_SetState(this, STOPWATCH_RUNNING);
			Segment_SetRunning(this->segment, true);
		}
		break;

	case STOPWATCH_RUNNING:
		if (Input_IsRisingEdge(this->stateButton))
		{
			StopwatchMode_SetState(this, STOPWATCH_PAUSED);
			Segment_SetRunning(this->segment, false);
		}
		break;

	case STOPWATCH_PAUSED:
		if (Input_IsRisingEdge(this->stateButton))
		{
			StopwatchMode_SetState(this, STOPWATCH_RUNNING);
			Segment_SetRunning(this->segment, true);
		}

		if (Input_IsRisingEdge(this->resetButton))
		{
			StopwatchMode_SetState(this, STOPWATCH_STOPPED);
			Segment_ResetCount(this->segment);
		}

		break;

	default:
		break;
	}

	Segment_Update(this->segment);
}
