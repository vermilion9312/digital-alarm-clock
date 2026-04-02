/*
 * output.h
 *
 *  Created on: Jan 17, 2026
 *      Author: LeeJooHo
 */

#ifndef COMMON_INC_OUTPUT_H_
#define COMMON_INC_OUTPUT_H_

#include <common.h>

typedef enum {
	OUTPUT_ACTIVE_LOW,
	OUTPUT_ACTIVE_HIGH
} OutputType;

typedef struct {
	GPIO_TypeDef* port;
	uint16_t      pin;
	OutputType    type;
} Output;

void Output_turnOn(const Output*);
void Output_turnOff(const Output*);
void Output_toggle(const Output*);

#endif /* COMMON_INC_OUTPUT_H_ */
