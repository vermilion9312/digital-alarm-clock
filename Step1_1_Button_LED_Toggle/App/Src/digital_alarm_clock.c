/*
 * digital_alarm_clock.c
 *
 *  Created on: Apr 2, 2026
 *      Author: LeeJooHo
 */


#include <digital_alarm_clock.h>

static DigitalAlarmClock this = {
		.button1 = { BUTTON_1_GPIO_Port, BUTTON_1_Pin, INPUT_ACTIVE_HIGH },
		.button2 = { BUTTON_2_GPIO_Port, BUTTON_2_Pin, INPUT_ACTIVE_HIGH },
		.button3 = { BUTTON_3_GPIO_Port, BUTTON_3_Pin, INPUT_ACTIVE_HIGH },

		.leftRed   = { LEFT_RED_GPIO_Port,   LEFT_RED_Pin,   OUTPUT_ACTIVE_LOW },
		.leftGreen = { LEFT_GREEN_GPIO_Port, LEFT_GREEN_Pin, OUTPUT_ACTIVE_LOW },
		.leftBlue  = { LEFT_BLUE_GPIO_Port,  LEFT_BLUE_Pin,  OUTPUT_ACTIVE_LOW },

		.rightRed   = { RIGHT_RED_GPIO_Port,   RIGHT_RED_Pin,   OUTPUT_ACTIVE_LOW },
		.rightGreen = { RIGHT_GREEN_GPIO_Port, RIGHT_GREEN_Pin, OUTPUT_ACTIVE_LOW },
		.rightBlue  = { RIGHT_BLUE_GPIO_Port,  RIGHT_BLUE_Pin,  OUTPUT_ACTIVE_LOW },
};

void DigitalAlarmClock_init(void)
{
	Output_turnOff(&this.leftRed);
	Output_turnOff(&this.leftGreen);
	Output_turnOff(&this.leftBlue);

	Output_turnOff(&this.rightRed);
	Output_turnOff(&this.rightGreen);
	Output_turnOff(&this.rightBlue);
}

void DigitalAlarmClock_operate(void)
{
	Input_update(&this.button1);
	Input_update(&this.button2);
	Input_update(&this.button3);

	if (Input_isRising(&this.button1))  Output_toggle(&this.leftRed);
	if (Input_isFalling(&this.button1)) Output_toggle(&this.rightRed);

	if (Input_isRising(&this.button2))  Output_toggle(&this.leftGreen);
	if (Input_isFalling(&this.button2)) Output_toggle(&this.rightGreen);

	if (Input_isRising(&this.button3))  Output_toggle(&this.leftBlue);
	if (Input_isFalling(&this.button3)) Output_toggle(&this.rightBlue);
}
