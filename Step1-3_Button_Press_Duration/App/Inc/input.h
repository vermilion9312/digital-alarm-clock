/*
 * input.h
 *
 *  Created on: Aug 29, 2026
 *      Author: LeeJooHo
 */

#ifndef INC_INPUT_H_
#define INC_INPUT_H_

#include <common.h>

typedef enum {
	INPUT_ACTIVE_LOW,
	INPUT_ACTIVE_HIGH
} InputLevel;

typedef struct {
	GPIO_TypeDef* port;
	uint16_t      pin;
	InputLevel    level;

	bool lastState;
	bool state;
} Input;

void Input_Init(Input*, GPIO_TypeDef*, uint16_t, InputLevel);
void Input_Update(Input*);
bool Input_IsRisingEdge(Input*);
bool Input_IsFallingEdge(Input*);
bool Input_IsOn(Input*);

#endif /* INC_INPUT_H_ */
