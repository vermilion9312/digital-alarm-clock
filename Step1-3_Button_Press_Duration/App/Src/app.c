/*
 * app.c
 *
 *  Created on: Aug 29, 2026
 *      Author: LeeJooHo
 */


#include <app.h>
#include <input.h>
#include <output.h>
#include <counter.h>
#include <segment.h>

extern TIM_HandleTypeDef htim6;

static Input button;

static Output leftRed;
static Output rightRed;

static Counter counter;

void App_Init(void)
{
	HAL_TIM_Base_Start_IT(&htim6);

	Input_Init(&button, BUTTON_1_GPIO_Port, BUTTON_1_Pin, INPUT_ACTIVE_HIGH);

	Output_Init(&leftRed,  LEFT_RED_GPIO_Port,  LEFT_RED_Pin,  OUTPUT_ACTIVE_LOW);
	Output_Init(&rightRed, RIGHT_RED_GPIO_Port, RIGHT_RED_Pin, OUTPUT_ACTIVE_LOW);

	Counter_Init(&counter);
	Segment_Init();
}

void App_Loop(void)
{
	Input_Update(&button);

	if (Input_IsRisingEdge(&button))
	{
		Output_Toggle(&leftRed);
		Counter_ResetCount(&counter);
	}

	if (Input_IsFallingEdge(&button)) Output_Toggle(&rightRed);

	Counter_SetRunning(&counter, Input_IsOn(&button));
	Segment_Update(Counter_GetCount(&counter), !Input_IsOn(&button));
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	if (htim->Instance != TIM6) return;

	Counter_IncreaseCount(&counter);
}

