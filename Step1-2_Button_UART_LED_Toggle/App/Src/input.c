/*
 * input.c
 *
 *  Created on: Aug 29, 2026
 *      Author: LeeJooHo
 */


#include <input.h>

void Input_Init(Input* this, GPIO_TypeDef* port, uint16_t pin, InputLevel level)
{
	this->port  = port;
	this->pin   = pin;
	this->level = level;

    this->state     = false;
    this->lastState = false;
}

void Input_Update(Input* this)
{
	this->lastState = this->state;
	bool rawState = HAL_GPIO_ReadPin(this->port, this->pin);
	this->state = (this->level) ? rawState : !rawState;
}

bool Input_IsRisingEdge(Input* this)
{
	return !this->lastState && this->state;
}

bool Input_IsFallingEdge(Input* this)
{
	return this->lastState && !this->state;
}
