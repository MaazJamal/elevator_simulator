/**
 * @file passengers_drop.h
 * @brief drops the passeger in corresponding floor
 */

#ifndef __PASSENEGRS_DROP_H__
#define __PASSENEGRS_DROP_H__
#include "structures.h"
#include "globals.h"

extern int passengers_drop(struct elevator elevator_arr[], int index, struct passenger *floor_arr[], int cur_floor, unsigned int event_time);

#endif
