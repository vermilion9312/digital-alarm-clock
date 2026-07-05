/*
 * input.h
 *
 *  Created on: Jan 17, 2026
 *      Author: LeeJooHo
 */

#ifndef COMMON_INC_INPUT_H_
#define COMMON_INC_INPUT_H_

#include <common.h>

typedef struct {
	GPIO_TypeDef* port;
	uint16_t      pin;
	ActiveLevel   level;
	bool          lastState;
	bool          state;
} Input;

bool Input_IsOn(const Input* );
bool Input_IsRising(const Input*);
bool Input_IsFalling(const Input*);
void Input_Update(Input*);

#endif /* COMMON_INC_INPUT_H_ */
