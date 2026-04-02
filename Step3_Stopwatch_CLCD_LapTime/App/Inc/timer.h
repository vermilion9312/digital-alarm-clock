/*
 * timer.h
 *
 *  Created on: Apr 2, 2026
 *      Author: LeeJooHo
 */

#ifndef INC_TIMER_H_
#define INC_TIMER_H_

#include <common.h>

typedef struct {
    volatile uint32_t count;
    volatile bool     active;
} Timer;

void Timer_init(Timer*);
void Timer_start(Timer*);
void Timer_stop(Timer*);
void Timer_resetCount(Timer*);
void Timer_tick(Timer*);
uint32_t Timer_getCount(Timer*);

#endif /* INC_TIMER_H_ */
