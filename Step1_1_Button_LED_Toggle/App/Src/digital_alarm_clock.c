/*
 * digital_alarm_clock.c
 *
 *  Created on: Apr 2, 2026
 *      Author: LeeJooHo
 */


#include <digital_alarm_clock.h>

static DigitalAlarmClock clock = {
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
	Output_turnOff(&clock.leftRed);
	Output_turnOff(&clock.leftGreen);
	Output_turnOff(&clock.leftBlue);

	Output_turnOff(&clock.rightRed);
	Output_turnOff(&clock.rightGreen);
	Output_turnOff(&clock.rightBlue);
}

void DigitalAlarmClock_operate(void)
{
	Input_update(&clock.button1);
	Input_update(&clock.button2);
	Input_update(&clock.button3);

	if (Input_isRising(&clock.button1))  Output_toggle(&clock.leftRed);
	if (Input_isFalling(&clock.button1)) Output_toggle(&clock.rightRed);

	if (Input_isRising(&clock.button2))  Output_toggle(&clock.leftGreen);
	if (Input_isFalling(&clock.button2)) Output_toggle(&clock.rightGreen);

	if (Input_isRising(&clock.button3))  Output_toggle(&clock.leftBlue);
	if (Input_isFalling(&clock.button3)) Output_toggle(&clock.rightBlue);
}
