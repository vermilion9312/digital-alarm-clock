/*
 * app_main.c
 *
 *  Created on: Apr 2, 2026
 *      Author: LeeJooHo
 */



#include <app_main.h>
#include <input.h>
#include <output.h>

static Input button1 = { BUTTON_1_GPIO_Port, BUTTON_1_Pin, ACTIVE_HIGH };

static Output leftRed  = { LEFT_RED_GPIO_Port,  LEFT_RED_Pin,  ACTIVE_LOW };
static Output rightRed = { RIGHT_RED_GPIO_Port, RIGHT_RED_Pin, ACTIVE_LOW };


void AppInit(void)
{

}

void AppLoop(void)
{
	Input_Update(&button1);
	if (Input_IsRising(&button1))  Output_Toggle(&leftRed);
	if (Input_IsFalling(&button1)) Output_Toggle(&rightRed);
}
