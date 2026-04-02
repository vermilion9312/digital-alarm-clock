/*
 * digital_alarm_clock.c
 *
 *  Created on: Apr 2, 2026
 *      Author: LeeJooHo
 */


#include <digital_alarm_clock.h>

extern TIM_HandleTypeDef htim6;

static DigitalAlarmClock clock = {
		.button1  = { BUTTON_1_GPIO_Port,  BUTTON_1_Pin,  INPUT_ACTIVE_HIGH },
		.button2  = { BUTTON_2_GPIO_Port,  BUTTON_2_Pin,  INPUT_ACTIVE_HIGH },
		.button3  = { BUTTON_3_GPIO_Port,  BUTTON_3_Pin,  INPUT_ACTIVE_HIGH },
		.button4  = { BUTTON_4_GPIO_Port,  BUTTON_4_Pin,  INPUT_ACTIVE_HIGH },

		.leftRed   = { LEFT_RED_GPIO_Port,   LEFT_RED_Pin,   OUTPUT_ACTIVE_LOW },
		.leftGreen = { LEFT_GREEN_GPIO_Port, LEFT_GREEN_Pin, OUTPUT_ACTIVE_LOW },
		.leftBlue  = { LEFT_BLUE_GPIO_Port,  LEFT_BLUE_Pin,  OUTPUT_ACTIVE_LOW },
		.rightRed  = { RIGHT_RED_GPIO_Port,  RIGHT_RED_Pin,  OUTPUT_ACTIVE_LOW },
};

static void setState(StopwatchState state)
{
	clock.state = state;
}


void DigitalAlarmClock_init(void)
{
	HAL_TIM_Base_Start_IT(&htim6);

	Output_turnOff(&clock.leftRed);
	Output_turnOff(&clock.leftGreen);
	Output_turnOff(&clock.leftBlue);
	Output_turnOff(&clock.rightRed);

	Segment_init(&clock.segment);
	Timer_init(&clock.timer);
}

void DigitalAlarmClock_operate(void)
{
	Input_update(&clock.button1);
	Input_update(&clock.button2);
	Input_update(&clock.button3);
	Input_update(&clock.button4);

	if (Input_isRising(&clock.button1)) Output_toggle(&clock.leftRed);
	if (Input_isRising(&clock.button2)) Output_toggle(&clock.leftGreen);
	if (Input_isRising(&clock.button3)) Output_toggle(&clock.leftBlue);
	if (Input_isRising(&clock.button4)) Output_toggle(&clock.rightRed);

	switch (clock.state)
	{
	case STATE_STOPPED:
		Timer_resetCount(&clock.timer);
		Timer_stop(&clock.timer);
		if (Input_isRising(&clock.button2)) setState(STATE_RUNNING);
		break;

	case STATE_RUNNING:
		Timer_start(&clock.timer);
		if (Input_isRising(&clock.button2)) setState(STATE_PAUSED);
		break;

	case STATE_PAUSED:
		Timer_stop(&clock.timer);
		if (Input_isRising(&clock.button2)) setState(STATE_RUNNING);
		if (Input_isRising(&clock.button3)) setState(STATE_STOPPED);
		break;

	default:
		break;
	}

	uint32_t currentCount = Timer_getCount(&clock.timer);
	uint8_t  seconds      = (currentCount / 1000) % 10;
	uint8_t  tenths       = (currentCount /  100) % 10;

	bool isBlinkPhase = (tenths < 5);
	bool shouldShowDgt1 = !(Input_isOn(&clock.button1) && isBlinkPhase);

	Segment_display(&clock.segment, seconds, shouldShowDgt1, tenths, false);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM6)
	{
		Timer_tick(&clock.timer);
	}
}

