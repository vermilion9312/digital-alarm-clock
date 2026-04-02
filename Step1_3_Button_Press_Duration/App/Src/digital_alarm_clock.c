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
		.leftRed  = { LEFT_RED_GPIO_Port,  LEFT_RED_Pin,  OUTPUT_ACTIVE_LOW },
		.rightRed = { RIGHT_RED_GPIO_Port, RIGHT_RED_Pin, OUTPUT_ACTIVE_LOW }
};

void DigitalAlarmClock_init(void)
{
	HAL_TIM_Base_Start_IT(&htim6);

	Output_turnOff(&clock.leftRed);
	Output_turnOff(&clock.rightRed);

	Segment_init(&clock.segment);
	Timer_init(&clock.timer);
}

void DigitalAlarmClock_operate(void)
{
	Input_update(&clock.button1);

	if (Input_isRising(&clock.button1))
	{
		Output_toggle(&clock.leftRed);
		Timer_resetCount(&clock.timer);
		Timer_start(&clock.timer);
	}

	if (Input_isFalling(&clock.button1))
	{
		Output_toggle(&clock.rightRed);
		Timer_stop(&clock.timer);
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

