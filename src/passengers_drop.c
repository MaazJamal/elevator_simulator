#include "passengers_drop.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "globals.h"
#include "structures.h"
#include "travel_log_file.h"
/**
 * The function takes in the elevator_array
 *
 * Removes the passenger from the floor and the elevator array.
 *
 * @return elevator array
 **/
int passengers_drop(struct elevator elevator_arr[], int index, struct passenger* floor_arr[], int cur_floor,unsigned int event_time)
{

	assert(index <= elevator_count);
	assert(cur_floor <= floor_count);
	assert(cur_floor == elevator_arr[index].cur_floor);

	
	int passenger_dropped = 0;
	int max_passenger = elevator_arr[index].max_passenger;
    //Loop to iterate the overall passengers in the elevator
	for(int i = 0; i < max_passenger; i++)
	{
		bool in_elevator = elevator_arr[index].passenger_arr[i].in_elevator;
		if(elevator_arr[index].passenger_arr[i].dest_floor == cur_floor && in_elevator)
		{
			elevator_arr[index].passenger_arr[i].in_elevator = false; //setting the status
			elevator_arr[index].passenger_count--;
			passenger_dropped++;
			struct passenger temp = elevator_arr[index].passenger_arr[i];
			travel_log_file(temp,event_time,index,1); //choose mode to write to travel_log as we are removing passenger.
		}
	
   }
   return passenger_dropped;
}
