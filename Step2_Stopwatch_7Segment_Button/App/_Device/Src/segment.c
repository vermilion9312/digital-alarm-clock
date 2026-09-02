/*
 * segment.c
 *
 *  Created on: Sep 1, 2026
 *      Author: LeeJooHo
 */


#include <segment.h>

void Segment_Init(void)
{
	_7SEG_GPIO_Init();
}

void Segment_Update(uint32_t count)
{
	int seconds = (int)((count / 1000) % 10);
	int  _100ms = (int)((count /  100) % 10);

	_7SEG_SetNumber(DGT1, seconds, (_100ms < 5 /*|| stopped*/) ? ON : OFF);
	_7SEG_SetNumber(DGT2,  _100ms, OFF);
}
