/*
 * app_main.c
 *
 *  Created on: Apr 2, 2026
 *      Author: LeeJooHo
 */



#include <app_main.h>
#include <input.h>
#include <output.h>

static void ChangeOutputDirection(void);

static Input button1 = { BUTTON_1_GPIO_Port, BUTTON_1_Pin, ACTIVE_HIGH };
static Input button2 = { BUTTON_2_GPIO_Port, BUTTON_2_Pin, ACTIVE_HIGH };
static Input button3 = { BUTTON_3_GPIO_Port, BUTTON_3_Pin, ACTIVE_HIGH };
static Input button4 = { BUTTON_3_GPIO_Port, BUTTON_3_Pin, ACTIVE_HIGH };

static Output leftRed    = { LEFT_RED_GPIO_Port,   LEFT_RED_Pin,   ACTIVE_LOW };
static Output leftBlue   = { LEFT_BLUE_GPIO_Port,  LEFT_BLUE_Pin,  ACTIVE_LOW };
static Output leftGreen  = { LEFT_GREEN_GPIO_Port, LEFT_GREEN_Pin, ACTIVE_LOW };

static Output rightRed    = { RIGHT_RED_GPIO_Port,   RIGHT_RED_Pin,   ACTIVE_LOW };
static Output rightBlue   = { RIGHT_BLUE_GPIO_Port,  RIGHT_BLUE_Pin,  ACTIVE_LOW };
static Output rightGreen  = { RIGHT_GREEN_GPIO_Port, RIGHT_GREEN_Pin, ACTIVE_LOW };

static Output* red;
static Output* blue;
static Output* green;

void AppInit(void)
{
	red   = &leftRed;
	blue  = &leftBlue;
	green = &leftGreen;
}

void AppLoop(void)
{
	Input_Update(&button1);
	Input_Update(&button2);
	Input_Update(&button3);
	Input_Update(&button4);

	if (Input_IsRising(&button4)) Output_Toggle(red);
	if (Input_IsRising(&button2)) Output_Toggle(blue);
	if (Input_IsRising(&button3)) Output_Toggle(green);
	if (Input_IsRising(&button4)) ChangeOutputDirection();
}

static void ChangeOutputDirection(void)
{
	if (red == &leftRed)
	{
		red   = &rightRed;
		blue  = &rightBlue;
		green = &rightGreen;
	}
	else
	{
		red   = &leftRed;
		blue  = &leftBlue;
		green = &leftGreen;
	}
}
