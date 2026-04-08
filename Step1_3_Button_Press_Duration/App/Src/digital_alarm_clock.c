/*
 * digital_alarm_clock.c
 *
 *  Created on: Apr 2, 2026
 *      Author: LeeJooHo
 */


#include <digital_alarm_clock.h>

extern TIM_HandleTypeDef htim6;

static DigitalAlarmClock this = {
		.button1  = { BUTTON_1_GPIO_Port,  BUTTON_1_Pin,  INPUT_ACTIVE_HIGH },
		.leftRed  = { LEFT_RED_GPIO_Port,  LEFT_RED_Pin,  OUTPUT_ACTIVE_LOW },
		.rightRed = { RIGHT_RED_GPIO_Port, RIGHT_RED_Pin, OUTPUT_ACTIVE_LOW }
};

void DigitalAlarmClock_init(void)
{
	HAL_TIM_Base_Start_IT(&htim6);

	Output_turnOff(&this.leftRed);
	Output_turnOff(&this.rightRed);

	Segment_init(&this.segment);
	Timer_init(&this.timer);
}

void DigitalAlarmClock_operate(void)
{
	Input_update(&this.button1);

	if (Input_isRising(&this.button1))
	{
		Output_toggle(&this.leftRed);
		Timer_resetCount(&this.timer);
		Timer_start(&this.timer);
	}

	if (Input_isFalling(&this.button1))
	{
		Output_toggle(&this.rightRed);
		Timer_stop(&this.timer);
	}

	uint32_t currentCount = Timer_getCount(&this.timer);
	uint8_t  seconds      = (currentCount / 1000) % 10;
	uint8_t  tenths       = (currentCount /  100) % 10;

	bool isBlinkPhase = (tenths < 5);
	bool shouldShowDgt1 = !(Input_isOn(&this.button1) && isBlinkPhase);

	Segment_display(&this.segment, seconds, shouldShowDgt1, tenths, false);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM6)
	{
		Timer_tick(&this.timer);
	}
}

