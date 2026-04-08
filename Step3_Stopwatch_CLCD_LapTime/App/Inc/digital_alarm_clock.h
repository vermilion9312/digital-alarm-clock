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
	void (* MainLogic_operate)(void);
	void (* IO_operate)(void);
	void (* Segment_operate)(void);
	void (* CLCD_operate)(void);
} Mode;

typedef enum {
	STATE_STOPPED,
	STATE_PAUSED,
	STATE_RUNNING
} StopwatchState;

typedef struct {
	Mode*  mode;

	Input  button1;
	Input  button2;
	Input  button3;
	Input  button4;

	Output leftRed;
	Output leftGreen;
	Output leftBlue;
	Output rightRed;

	Segment segment;
	Timer   timer;

	StopwatchState state;
} DigitalAlarmClock;

void DigitalAlarmClock_init(void);
void DigitalAlarmClock_operate(void);

#endif /* INC_DIGITAL_ALARM_CLOCK_H_ */
