#include <stdio.h>
#include "../include/globals.h"
#include "../include/max_waiting_time.h"

/**
 * @file max_waiting_time.c
 *
 * @brief Calculates the maximum waiting time for the passengers
 *
 * @author Ritika Arora - ritikaarora@cmail.carleton.ca
 *
 * @detail The function is to measure the maximum time the passengers took to wait to get into
 * the elevator.
 * The function compares the time given as an input with static variable max_time. If the input
 * time is greater than the max time , then that time value is stored as max time.
 *
 * @param[in] time_difference, the input parameter which is the difference between the time
 * passenger arrived and the time passenger got into the elevator
 *
 * @return float Returns the maximum waiting time.
*/

float max_waiting_time(float time_difference)
{
	static float max_time;
	if (time_difference > max_time)
	{
		max_time = time_difference;
	}
	return max_time;
}
