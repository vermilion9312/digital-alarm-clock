/*
 * input.h
 *
 *  Created on: Jan 17, 2026
 *      Author: LeeJooHo
 */

#ifndef COMMON_INC_INPUT_H_
#define COMMON_INC_INPUT_H_

#include <common.h>

typedef enum {
	INPUT_ACTIVE_LOW,
	INPUT_ACTIVE_HIGH
} InputType;

typedef struct {
	GPIO_TypeDef* port;
	uint16_t      pin;
	InputType     type;
	bool          lastState;
	bool          state;
} Input;

bool Input_isOn(const Input*);
bool Input_isRising(const Input*);
bool Input_isFalling(const Input*);
void Input_update(Input*);

#endif /* COMMON_INC_INPUT_H_ */
