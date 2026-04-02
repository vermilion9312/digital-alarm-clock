/*
 * input.c
 *
 *  Created on: Jan 17, 2026
 *      Author: LeeJooHo
 */


#include <input.h>

bool Input_isOn(const Input* this)
{
	return this->state;
}

bool Input_isRising(const Input* this)
{
	return !this->lastState && this->state;
}

bool Input_isFalling(const Input* this)
{
	return this->lastState && !this->state;
}

void Input_update(Input* this)
{
	this->lastState = this->state;
	bool state = HAL_GPIO_ReadPin(this->port, this->pin);
	this->state = (this->type == INPUT_ACTIVE_HIGH) ? state : !state;
}

