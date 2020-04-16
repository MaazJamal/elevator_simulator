#include <stdio.h>
#include "../include/globals.h"
#include "../include/average_waiting_time.h"

/*
*@brief Calculates the average waiting time for the passengers
*
*@detail The function is to measure the average time the passengers took to wait to get into
* the elevator.
*
*@param[in] time_difference, the input parameter which is the difference between the time passenger
* arrived and the time passenger got into the elevator
* The function has two static variables: counter and average_waiting_time, which stores the value
* from the previous runs of the function.
* Firstly, it checks if the input parameter is positive or negative. If it is negative, it will
* just return the average waiting time which is already stored in it without doing any
* calculations.
* If the input is a positive value , then it increments the counter and does the calculation to
* get the average waiting time.
*
* @return float Returns the average waiting time.
*/

float average_waiting_time(float time_difference){
	static int counter;
	static float average_time;
	float differential;
	if(time_difference < 0){
		//printf("Average Time:%f\n",average_time);
		return average_time;
	}
	else{
		counter++;
		differential = (time_difference - average_time)/counter;
		average_time = average_time + differential;
		//printf("Average Time:%f\n",average_time);
	}
	return average_time;
}
