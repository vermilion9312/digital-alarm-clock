/*
 * input.c
 *
 *  Created on: Jan 17, 2026
 *      Author: LeeJooHo
 */


#include <input.h>

bool Input_IsOn(const Input* this)
{
	return this->state;
}

bool Input_IsRising(const Input* this)
{
	return !this->lastState && this->state;
}

bool Input_IsFalling(const Input* this)
{
	return this->lastState && !this->state;
}

void Input_Update(Input* this)
{
	this->lastState = this->state;
	bool state = HAL_GPIO_ReadPin(this->port, this->pin);
	this->state = (this->level == ACTIVE_HIGH) ? state : !state;
}

