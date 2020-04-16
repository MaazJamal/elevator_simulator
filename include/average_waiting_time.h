/**@file average_waiting_time.h
 *@brief Has the declaration for the average_waiting_time function
 *@detail The function has one input parameter: time_difference which is the difference between
 * the time passenger arrived and the time he got into the elevator
 *@return float returns the average time taken by the passengers waiting to get into the elevator
 **/

#ifndef AVERAGE_WAITING_TIME_H_INCLUDED
#define AVERAGE_WAITING_TIME_H_INCLUDED
#include "structures.h"
#include "globals.h"

extern float average_waiting_time(float time_difference);

#endif // AVERAGE_WAITING_TIME_H_INCLUDED
