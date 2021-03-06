/**
 * @file passengers_take_in.c
 * @brief contains the definition of passengers_take_in
 * 
 * @author Maaz Jamal
 * 
 * */

#include "passengers_take_in.h"
#include <assert.h>
#include <stdbool.h>
#include "globals.h"
#include "remove_passenger_floor.h"
#include <stdio.h>
#include "travel_log_file.h"

/** This function removes adds a passenger from a queue to the elevator_array 
 * 
 *  This function take in an elevator, index of the elevator,  array of floor and current_floor.
 * and removes the passenger from the floor and adds it to elevator passenger array.   
 * @param[in] index int value that specifies the index of the elevator. index start at 0.
 * @param[in, out] elevator_arr pointer to elevator array.
 * @param[in, out] floor_arr array of pointers to passengers on floor.
 * @param[in] cur_florr int value that specifies the current floor. As described in elevator so start at 1 and equal to max_floor_count.
 * @param[in] event_time unsigned int the time the event has happened.
 * @return return the number of passengers added to the elevator.
 * */
int passengers_take_in(struct elevator elevator_arr[], int index, struct passenger *floor_arr[], int cur_floor, unsigned int event_time)
{

	assert(index < elevator_count && index >= 0);
	assert(cur_floor <= floor_count && cur_floor > 0);
	assert(cur_floor == elevator_arr[index].cur_floor); //? test the case that both elevator and passenger are at same floor.

	int floor_index = cur_floor - 1; //input file floor start from 1 while floor array is indexed from 0 so this is needed
	int passenger_capacity = elevator_arr[index].max_passenger;
	int passenger_added = 0;

	for (int i = 0; i < passenger_capacity; i++)
	{

		if (!(elevator_arr[index].passenger_arr[i].in_elevator))
		{

			if (floor_arr[floor_index] != NULL && elevator_arr[index].passenger_count < passenger_capacity)
			{
				struct passenger temp = *(floor_arr[floor_index]);
				elevator_arr[index].passenger_arr[i] = temp;
				elevator_arr[index].passenger_arr[i].in_elevator = true;
				elevator_arr[index].passenger_count++;
				elevator_arr[index].stop_at_floor[temp.dest_floor - 1] = true; //stop at this floor from drop off
				passenger_added++;
				travel_log_file(*(floor_arr[floor_index]), event_time, index, 2); //choose mode to calculate avg,max times.
				remove_passenger_floor(floor_arr, cur_floor);
			}
			else
			{
				break;
			}
		}
	}
	return passenger_added;
}