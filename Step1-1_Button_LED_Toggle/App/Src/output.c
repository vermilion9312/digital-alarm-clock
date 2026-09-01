/*
 * output.c
 *
 *  Created on: Aug 29, 2026
 *      Author: LeeJooHo
 */


#include <output.h>

void Output_TurnOn(Output* this)
{
	GPIO_PinState pinState = (this->level == OUTPUT_ACTIVE_HIGH) ? GPIO_PIN_SET : GPIO_PIN_RESET;
	HAL_GPIO_WritePin(this->port, this->pin, pinState);
	this->state = true;
}

void Output_TurnOff(Output* this)
{
	GPIO_PinState pinState = (this->level == OUTPUT_ACTIVE_HIGH) ? GPIO_PIN_RESET : GPIO_PIN_SET;
	HAL_GPIO_WritePin(this->port, this->pin, pinState);
	this->state = false;
}

void Output_Toggle(Output* this)
{
	this->state ? Output_TurnOff(this) : Output_TurnOn(this);
}

void Output_Init(Output* this, GPIO_TypeDef* port, uint16_t pin, OutputLevel level)
{
	this->port  = port;
	this->pin   = pin;
	this->level = level;

	Output_TurnOff(this);
}
