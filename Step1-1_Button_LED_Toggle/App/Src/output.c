/*
 * output.c
 *
 *  Created on: Jan 17, 2026
 *      Author: LeeJooHo
 */


#include <output.h>

void Output_TurnOn(Output* this)
{
	bool level = (this->level == ACTIVE_HIGH) ? GPIO_PIN_SET : GPIO_PIN_RESET;
	HAL_GPIO_WritePin(this->port, this->pin, level);
	this->state = true;
}

void Output_TurnOff(Output* this)
{
	bool level = (this->level == ACTIVE_HIGH) ? GPIO_PIN_RESET : GPIO_PIN_SET;
	HAL_GPIO_WritePin(this->port, this->pin, level);
	this->state = false;
}

void Output_Toggle(Output* this)
{
	this->state ? Output_TurnOff(this) : Output_TurnOn(this);
}
