/*
 * app.c
 *
 *  Created on: Aug 29, 2026
 *      Author: LeeJooHo
 */


#include <app.h>
#include <stopwatch_mode.h>
#include <output.h>

typedef enum {
	APP_CLOCK_MODE,
	APP_ALARM_MODE,
	APP_STOPWATHCH_MODE,
	APP_TIMER_MODE
} AppMode;

extern TIM_HandleTypeDef htim6;

static Input button_1;
static Input button_2;
static Input button_3;
static Input button_4;

static Output leftRed;
static Output leftGreen;
static Output leftBlue;
static Output rightRed;

static Counter counter;
static Segment segment;

static StopwatchMode stopwatchMode;

static AppMode mode;

void App_Init(void)
{
	HAL_TIM_Base_Start_IT(&htim6);

	Input_Init(&button_1, BUTTON_1_GPIO_Port, BUTTON_1_Pin, INPUT_ACTIVE_HIGH);
	Input_Init(&button_2, BUTTON_2_GPIO_Port, BUTTON_2_Pin, INPUT_ACTIVE_HIGH);
	Input_Init(&button_3, BUTTON_3_GPIO_Port, BUTTON_3_Pin, INPUT_ACTIVE_HIGH);
	Input_Init(&button_4, BUTTON_4_GPIO_Port, BUTTON_4_Pin, INPUT_ACTIVE_HIGH);

	Output_Init(&leftRed,   LEFT_RED_GPIO_Port,   LEFT_RED_Pin,   OUTPUT_ACTIVE_LOW);
	Output_Init(&leftGreen, LEFT_GREEN_GPIO_Port, LEFT_GREEN_Pin, OUTPUT_ACTIVE_LOW);
	Output_Init(&leftBlue,  LEFT_BLUE_GPIO_Port,  LEFT_BLUE_Pin,  OUTPUT_ACTIVE_LOW);
	Output_Init(&rightRed,  RIGHT_RED_GPIO_Port,  RIGHT_RED_Pin,  OUTPUT_ACTIVE_LOW);

	Counter_Init(&counter);
	Segment_Init(&segment, &counter);

	StopwatchMode_Init(&stopwatchMode, &button_2, &button_3, &segment);

	mode = APP_STOPWATHCH_MODE;
}

void App_Loop(void)
{
	Input_Update(&button_1);
	Input_Update(&button_2);
	Input_Update(&button_3);
	Input_Update(&button_4);

	if (Input_IsRisingEdge(&button_1)) Output_Toggle(&leftRed);
	if (Input_IsRisingEdge(&button_2)) Output_Toggle(&leftGreen);
	if (Input_IsRisingEdge(&button_3)) Output_Toggle(&leftBlue);
	if (Input_IsRisingEdge(&button_4)) Output_Toggle(&rightRed);

	switch (mode)
	{
	case APP_CLOCK_MODE:
		break;

	case APP_ALARM_MODE:
		break;

	case APP_STOPWATHCH_MODE:
		StopwatchMode_Update(&stopwatchMode);
		break;

	case APP_TIMER_MODE:
		break;

	default:
		break;
	}
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance != TIM6) return;

	Counter_IncreaseCount(&counter);
}

