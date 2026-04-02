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
		.button4 = { BUTTON_4_GPIO_Port, BUTTON_4_Pin, INPUT_ACTIVE_HIGH },

		.leftRed   = { LEFT_RED_GPIO_Port,   LEFT_RED_Pin,   OUTPUT_ACTIVE_LOW },
		.leftGreen = { LEFT_GREEN_GPIO_Port, LEFT_GREEN_Pin, OUTPUT_ACTIVE_LOW },
		.leftBlue  = { LEFT_BLUE_GPIO_Port,  LEFT_BLUE_Pin,  OUTPUT_ACTIVE_LOW },

		.rightRed   = { RIGHT_RED_GPIO_Port,   RIGHT_RED_Pin,   OUTPUT_ACTIVE_LOW },
		.rightGreen = { RIGHT_GREEN_GPIO_Port, RIGHT_GREEN_Pin, OUTPUT_ACTIVE_LOW },
		.rightBlue  = { RIGHT_BLUE_GPIO_Port,  RIGHT_BLUE_Pin,  OUTPUT_ACTIVE_LOW },

		.red   = &clock.leftRed,
		.green = &clock.leftGreen,
		.blue  = &clock.leftBlue

};

static void changeOutputDirection(void)
{
	if (clock.red == &clock.leftRed)
	{
		clock.red   = &clock.rightRed;
		clock.green = &clock.rightGreen;
		clock.blue  = &clock.rightBlue;
	}
	else
	{
		clock.red   = &clock.leftRed;
		clock.green = &clock.leftGreen;
		clock.blue  = &clock.leftBlue;
	}
}

void DigitalAlarmClock_init(void)
{
	Output_turnOff(clock.red);
	Output_turnOff(clock.green);
	Output_turnOff(clock.blue);
}

void DigitalAlarmClock_operate(void)
{
	Input_update(&clock.button1);
	Input_update(&clock.button2);
	Input_update(&clock.button3);
	Input_update(&clock.button4);

	if (Input_isRising(&clock.button1))  Output_toggle(clock.red);
	if (Input_isRising(&clock.button2))  Output_toggle(clock.green);
	if (Input_isRising(&clock.button3))  Output_toggle(clock.blue);
	if (Input_isRising(&clock.button4))  changeOutputDirection();
}
