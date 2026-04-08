/*
 * digital_alarm_clock.c
 *
 *  Created on: Apr 2, 2026
 *      Author: LeeJooHo
 */


#include <digital_alarm_clock.h>

extern TIM_HandleTypeDef htim6;

static void MainLogic_opereate(void);
static void IO_operate(void);
static void Segment_operate(void);
static void CLCD_operate(void);

static Mode stopwatchMode = { MainLogic_opereate,  IO_operate, Segment_operate, CLCD_operate };

static DigitalAlarmClock this = {
		.mode = &stopwatchMode,

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
	this.state = state;
}


void DigitalAlarmClock_init(void)
{
	HAL_TIM_Base_Start_IT(&htim6);

	Output_turnOff(&this.leftRed);
	Output_turnOff(&this.leftGreen);
	Output_turnOff(&this.leftBlue);
	Output_turnOff(&this.rightRed);

	Segment_init(&this.segment);
	Timer_init(&this.timer);
}

void DigitalAlarmClock_operate(void)
{
	this.mode->MainLogic_operate();
	this.mode->IO_operate();
	this.mode->Segment_operate();
	this.mode->CLCD_operate();
}

static void MainLogic_opereate(void)
{
	switch (this.state)
	{
	case STATE_STOPPED:
		Timer_resetCount(&this.timer);
		Timer_stop(&this.timer);
		if (Input_isRising(&this.button2)) setState(STATE_RUNNING);
		break;

	case STATE_RUNNING:
		Timer_start(&this.timer);
		if (Input_isRising(&this.button2)) setState(STATE_PAUSED);
		break;

	case STATE_PAUSED:
		Timer_stop(&this.timer);
		if (Input_isRising(&this.button2)) setState(STATE_RUNNING);
		if (Input_isRising(&this.button3)) setState(STATE_STOPPED);
		break;

	default:
		break;
	}
}

static void IO_operate(void)
{
	Input_update(&this.button1);
	Input_update(&this.button2);
	Input_update(&this.button3);
	Input_update(&this.button4);

	if (Input_isRising(&this.button1)) Output_toggle(&this.leftRed);
	if (Input_isRising(&this.button2)) Output_toggle(&this.leftGreen);
	if (Input_isRising(&this.button3)) Output_toggle(&this.leftBlue);
	if (Input_isRising(&this.button4)) Output_toggle(&this.rightRed);
}

static void Segment_operate(void)
{
	uint32_t currentCount = Timer_getCount(&this.timer);
	uint8_t  seconds      = (currentCount / 1000) % 10;
	uint8_t  tenths       = (currentCount /  100) % 10;

	bool isBlinkPhase = (tenths < 5);
	bool shouldShowDgt1 = !(Input_isOn(&this.button1) && isBlinkPhase);

	Segment_display(&this.segment, seconds, shouldShowDgt1, tenths, false);
}

static void CLCD_operate(void)
{

}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance == TIM6)
	{
		Timer_tick(&this.timer);
	}
}

