/** @file passengers_take_in.h 
 * @brief contains declarations for passenger_take_in function. Used to add 
 passenger to the provided elevator array entry 

 @author Maaz Jamal
*/

#ifndef __PASSENGERS_TAKE_IN_H__
#define __PASSENGERS_TAKE_IN_H__
#include "structures.h"

extern int passengers_take_in(struct elevator elevator_arr[], int index, struct passenger *floor_arr[], int cur_floor, unsigned int event_time);

#endif