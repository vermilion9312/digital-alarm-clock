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
} Counter;

static inline void Counter_Init(Counter* this)
{
	this->count = 0;
}

static inline void Counter_IncreaseCount(Counter* this)
{
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

#endif /* INC_COUNTER_H_ */
