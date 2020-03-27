#include "passengers_take_in.h"
#include <assert.h>
#include <stdbool.h>
#include "globals.h"
#include "remove_passenger_floor.h"

int passengers_take_in(struct elevator elevator_arr[], int index, struct passenger* floor_arr[], int cur_floor){

	assert(index >= elevator_count); 
	assert(cur_floor >= floor_count);
	assert(cur_floor == elevator_arr[index].cur_floor);

	int passenger_capacity = elevator_arr[index].max_passenger;
	int passenger_added = 0;

	for(int i = 0; i < passenger_capacity; i++){

		if(!(elevator_arr[index].passenger_arr[i].in_elevator)){
		
			if(floor_arr[cur_floor] != NULL && elevator_arr[index].passenger_count < passenger_capacity){
			elevator_arr[index].passenger_arr[i] = *(floor_arr[cur_floor]);
			elevator_arr[index].passenger_arr[i].in_elevator = true;
			elevator_arr[index].passenger_count++;
			passenger_added++;
			remove_passenger_floor(floor_arr,cur_floor);
			}
			else{
				break;
			}

		}
	}
	return passenger_added;
}