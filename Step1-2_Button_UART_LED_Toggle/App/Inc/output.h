/*
 * output.h
 *
 *  Created on: Aug 29, 2026
 *      Author: LeeJooHo
 */

#ifndef INC_OUTPUT_H_
#define INC_OUTPUT_H_

#include <common.h>

typedef enum {
	OUTPUT_ACTIVE_LOW,
	OUTPUT_ACTIVE_HIGH
} OutputLevel;

typedef struct {
	GPIO_TypeDef* port;
	uint16_t      pin;
	OutputLevel   level;

	bool state;
} Output;

void Output_TurnOn(Output*);
void Output_TurnOff(Output*);
void Output_Toggle(Output*);
void Output_Init(Output*, GPIO_TypeDef*, uint16_t, OutputLevel);

#endif /* INC_OUTPUT_H_ */
