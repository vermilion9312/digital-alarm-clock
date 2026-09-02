/*
 * counter.h
 *
 *  Created on: Sep 1, 2026
 *      Author: LeeJooHo
 */

#ifndef INC_COUNTER_H_
#define INC_COUNTER_H_

#include <common.h>

typedef struct {
	uint32_t count;
	bool running;
} Counter;

static inline void Counter_Init(Counter* this)
{
	this->count = 0;
	this->running = false;
}

static inline void Counter_IncreaseCount(Counter* this)
{
	if (!this->running) return;
	this->count++;
}

static inline void Counter_ResetCount(Counter* this)
{
	this->count = 0;
}

static inline uint32_t Counter_GetCount(Counter* this)
{
	return this->count;
}

static inline void Counter_SetRunning(Counter* this, bool running)
{
	this->running = running;
}

#endif /* INC_COUNTER_H_ */
