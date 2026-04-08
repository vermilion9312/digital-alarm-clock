/*
 * char_lcd.c
 *
 *  Created on: Apr 4, 2026
 *      Author: LeeJooHo
 */


#include <char_lcd.h>

void CharLcd_init(CharLcd* this)
{
	CLCD_GPIO_Init();
	CLCD_Init();
}
