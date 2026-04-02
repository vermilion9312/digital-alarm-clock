/*
 * digital_alarm_clock.h
 *
 *  Created on: Apr 2, 2026
 *      Author: LeeJooHo
 */

#ifndef INC_DIGITAL_ALARM_CLOCK_H_
#define INC_DIGITAL_ALARM_CLOCK_H_

#include <input.h>
#include <output.h>
#include <segment.h>
#include <timer.h>

typedef struct {
	Input  button1;
	Output leftRed;
	Output rightRed;
	Segment segment;
	Timer   timer;
} DigitalAlarmClock;

void DigitalAlarmClock_init(void);
void DigitalAlarmClock_operate(void);

#endif /* INC_DIGITAL_ALARM_CLOCK_H_ */
