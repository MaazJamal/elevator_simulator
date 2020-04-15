#include "passengers_drop.h"
#include <assert.h>
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include "globals.h"
/**
 * The function takes in the elevator_array
 *
 * Removes the passenger from the floor and the elevator array.
 *
 * @return elevator array
 **/
int passengers_drop(struct elevator elevator_arr[], int index, struct passenger* floor_arr[], int cur_floor)
{

	assert(index <= elevator_count);
	assert(cur_floor <= floor_count);
	assert(cur_floor != elevator_arr[index].cur_floor);

	
	int passenger_dropped = passenger_capacity;
    //Loop to iterate the overall passengers in the elevator
	for(int i = 0; i < passenger_capacity; i++)
	{
		if(elevator_arr[index].passenger_arr[i].dest_floor == cur_floor)
		{
			elevator_arr[index].passenger_arr[i].in_elevator = false; //setting the status
			elevator_arr[index].passenger_count--;
			passenger_dropped++;
		}
		else
		{
			break;
		}
	
	return 1;
   }
}
