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
		.button4 = { BUTTON_4_GPIO_Port, BUTTON_4_Pin, INPUT_ACTIVE_HIGH },

		.leftRed   = { LEFT_RED_GPIO_Port,   LEFT_RED_Pin,   OUTPUT_ACTIVE_LOW },
		.leftGreen = { LEFT_GREEN_GPIO_Port, LEFT_GREEN_Pin, OUTPUT_ACTIVE_LOW },
		.leftBlue  = { LEFT_BLUE_GPIO_Port,  LEFT_BLUE_Pin,  OUTPUT_ACTIVE_LOW },

		.rightRed   = { RIGHT_RED_GPIO_Port,   RIGHT_RED_Pin,   OUTPUT_ACTIVE_LOW },
		.rightGreen = { RIGHT_GREEN_GPIO_Port, RIGHT_GREEN_Pin, OUTPUT_ACTIVE_LOW },
		.rightBlue  = { RIGHT_BLUE_GPIO_Port,  RIGHT_BLUE_Pin,  OUTPUT_ACTIVE_LOW },

		.red   = &this.leftRed,
		.green = &this.leftGreen,
		.blue  = &this.leftBlue

};

static void changeOutputDirection(void)
{
	if (this.red == &this.leftRed)
	{
		this.red   = &this.rightRed;
		this.green = &this.rightGreen;
		this.blue  = &this.rightBlue;
	}
	else
	{
		this.red   = &this.leftRed;
		this.green = &this.leftGreen;
		this.blue  = &this.leftBlue;
	}
}

void DigitalAlarmClock_init(void)
{
	Output_turnOff(this.red);
	Output_turnOff(this.green);
	Output_turnOff(this.blue);
}

void DigitalAlarmClock_operate(void)
{
	Input_update(&this.button1);
	Input_update(&this.button2);
	Input_update(&this.button3);
	Input_update(&this.button4);

	if (Input_isRising(&this.button1))  Output_toggle(this.red);
	if (Input_isRising(&this.button2))  Output_toggle(this.green);
	if (Input_isRising(&this.button3))  Output_toggle(this.blue);
	if (Input_isRising(&this.button4))  changeOutputDirection();
}
