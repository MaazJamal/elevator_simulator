/*@file is_lift_empty.h
 *@brief Has the declaration for the is_lift_empty function
 *@detail The function has two input parameters: one is an array of elevators of elevator type
 *@detail and the other is the index of the array which can be used as the number of the elevator
 */

#ifndef IS_LIFT_EMPTY_H_INCLUDED
#define IS_LIFT_EMPTY_H_INCLUDED
#include "structures.h"
#include "globals.h"

extern int is_lift_empty(struct elevator elevator_arr[], unsigned int index);

#endif // IS_LIFT_EMPTY_H_INCLUDED
