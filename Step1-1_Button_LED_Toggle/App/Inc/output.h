/*
 * output.h
 *
 *  Created on: Jan 17, 2026
 *      Author: LeeJooHo
 */

#ifndef COMMON_INC_OUTPUT_H_
#define COMMON_INC_OUTPUT_H_

#include <common.h>

typedef struct {
	GPIO_TypeDef* port;
	uint16_t      pin;
	ActiveLevel   level;
	bool          state;
} Output;

void Output_TurnOn(Output*);
void Output_TurnOff(Output*);
void Output_Toggle(Output*);

#endif /* COMMON_INC_OUTPUT_H_ */
