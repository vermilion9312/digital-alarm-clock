/*
 * segment.c
 *
 *  Created on: Apr 2, 2026
 *      Author: LeeJooHo
 */


#include <segment.h>

void Segment_init(Segment* this)
{
	(void) this;

	_7SEG_GPIO_Init();
}

void Segment_display(Segment* this, uint8_t digit1, bool isDot1On, uint8_t digit2, bool isDot2On)
{
    _7SEG_SetNumber(DGT1, digit1, isDot1On ? ON : OFF);
    _7SEG_SetNumber(DGT2, digit2, isDot2On ? ON : OFF);
}
