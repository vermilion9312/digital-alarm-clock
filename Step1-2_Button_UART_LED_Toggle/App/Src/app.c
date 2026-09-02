/*
 * app.c
 *
 *  Created on: Aug 29, 2026
 *      Author: LeeJooHo
 */


#include <app.h>
#include <input.h>
#include <output.h>

static Input button_1;
static Input button_2;
static Input button_3;
static Input button_4;

static Output leftRed;
static Output leftGreen;
static Output leftBlue;

static Output rightRed;
static Output rightGreen;
static Output rightBlue;

static Output* ledRed;
static Output* ledGreen;
static Output* ledBlue;

static void App_SwitchLedSide(void)
{
	if (ledRed == &leftRed)
	{
		ledRed   = &rightRed;
		ledGreen = &rightGreen;
		ledBlue  = &rightBlue;
	}
	else
	{
		ledRed   = &leftRed;
		ledGreen = &leftGreen;
		ledBlue  = &leftBlue;
	}
}

void App_Init(void)
{
	Input_Init(&button_1, BUTTON_1_GPIO_Port, BUTTON_1_Pin, INPUT_ACTIVE_HIGH);
	Input_Init(&button_2, BUTTON_2_GPIO_Port, BUTTON_2_Pin, INPUT_ACTIVE_HIGH);
	Input_Init(&button_3, BUTTON_3_GPIO_Port, BUTTON_3_Pin, INPUT_ACTIVE_HIGH);
	Input_Init(&button_4, BUTTON_4_GPIO_Port, BUTTON_4_Pin, INPUT_ACTIVE_HIGH);

	Output_Init(&leftRed,   LEFT_RED_GPIO_Port,   LEFT_RED_Pin,   OUTPUT_ACTIVE_LOW);
	Output_Init(&leftGreen, LEFT_GREEN_GPIO_Port, LEFT_GREEN_Pin, OUTPUT_ACTIVE_LOW);
	Output_Init(&leftBlue,  LEFT_BLUE_GPIO_Port,  LEFT_BLUE_Pin,  OUTPUT_ACTIVE_LOW);

	Output_Init(&rightRed,   RIGHT_RED_GPIO_Port,   RIGHT_RED_Pin,   OUTPUT_ACTIVE_LOW);
	Output_Init(&rightGreen, RIGHT_GREEN_GPIO_Port, RIGHT_GREEN_Pin, OUTPUT_ACTIVE_LOW);
	Output_Init(&rightBlue,  RIGHT_BLUE_GPIO_Port,  RIGHT_BLUE_Pin,  OUTPUT_ACTIVE_LOW);

	ledRed   = &leftRed;
	ledGreen = &leftGreen;
	ledBlue  = &leftBlue;
}

void App_Loop(void)
{
	Input_Update(&button_1);
	Input_Update(&button_2);
	Input_Update(&button_3);
	Input_Update(&button_4);

	if (Input_IsRisingEdge(&button_4)) App_SwitchLedSide();

	if (Input_IsRisingEdge(&button_1)) Output_Toggle(ledRed);
	if (Input_IsRisingEdge(&button_2)) Output_Toggle(ledGreen);
	if (Input_IsRisingEdge(&button_3)) Output_Toggle(ledBlue);
}
