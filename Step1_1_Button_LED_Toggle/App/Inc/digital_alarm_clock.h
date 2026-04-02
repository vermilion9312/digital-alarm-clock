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

typedef struct {
	Input button1;
	Input button2;
	Input button3;

	Output leftRed;
	Output leftGreen;
	Output leftBlue;

	Output rightRed;
	Output rightGreen;
	Output rightBlue;
} DigitalAlarmClock;

void DigitalAlarmClock_init(void);
void DigitalAlarmClock_operate(void);

#endif /* INC_DIGITAL_ALARM_CLOCK_H_ */
