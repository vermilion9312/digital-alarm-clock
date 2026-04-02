/*
 * segment.h
 *
 *  Created on: Apr 2, 2026
 *      Author: LeeJooHo
 */

#ifndef INC_SEGMENT_H_
#define INC_SEGMENT_H_

#include <common.h>
#include <7SEG.h>

typedef struct {

} Segment;

void Segment_init(Segment*);
void Segment_display(Segment*, uint8_t, bool, uint8_t, bool);

#endif /* INC_SEGMENT_H_ */
