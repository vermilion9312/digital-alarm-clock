/*
 * app_main.c
 *
 *  Created on: Apr 2, 2026
 *      Author: LeeJooHo
 */



#include <app_main.h>
#include <digital_alarm_clock.h>

void appInit(void)
{
	DigitalAlarmClock_init();
}

void appLoop(void)
{
	DigitalAlarmClock_operate();
}
