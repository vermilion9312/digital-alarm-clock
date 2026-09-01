/*
 * segment.h
 *
 *  Created on: Sep 1, 2026
 *      Author: LeeJooHo
 */

#ifndef INC_SEGMENT_H_
#define INC_SEGMENT_H_

#include <counter.h>
#include <7SEG.h>

typedef struct {
	Counter* counter;
} Segment;

void Segment_Init(Segment*, Counter*);
void Segment_Update(Segment*);
void Segment_SetRunning(Segment*, bool);
void Segment_ResetCount(Segment*);

#endif /* INC_SEGMENT_H_ */
