/*
 * timer.c
 *
 *  Created on: Apr 2, 2026
 *      Author: LeeJooHo
 */


#include <timer.h>

void Timer_init(Timer* this)
{
    this->count  = 0;
    this->active = false;
}

void Timer_start(Timer* this)
{
    this->active = true;
}

void Timer_stop(Timer* this)
{
    this->active = false;
}

void Timer_resetCount(Timer* this)
{
    this->count = 0;
}

void Timer_tick(Timer* this)
{
    if (this->active) this->count++;
}

uint16_t Timer_getCount(Timer* this)
{
    return this->count;
}
