/**@file max_waiting_time.h
 *@brief Has the declaration for the max_waiting_time function
 *@detail The function has one input parameter: time_difference which is the difference between
 * the time passenger arrived and the time he got into the elevator
 *@return float returns the maximum time taken by a passenger
 **/

#ifndef MAX_WAITING_TIME_H_INCLUDED
#define MAX_WAITING_TIME_H_INCLUDED
#include "structures.h"
#include "globals.h"

extern float max_waiting_time(float time_difference);

#endif // MAX_WAITING_TIME_H_INCLUDED
