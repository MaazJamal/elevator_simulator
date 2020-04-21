#include "remove_passenger_floor.h"
#include"structures.h"
#include <assert.h>
#include <stdlib.h>
#include "globals.h"
#include "stdio.h"

/**
Removes the passenger details from floor specified.

Constraints
The program terminates if the input parameter cur_floor(passenger details for this particular floor has to be deleted)is erraneous.
(i.e)cur_floor must be within the range 1-100 and less than the floor_count(Total number of floors in the building )

Returns 1 on successful deletion of passenger details from specified floor.
**/

int remove_passenger_floor(struct passenger* floordetails[], int cur_floor){

	assert(cur_floor >0);//checks the value of cur_floor ;if it returns 0- terminates the program
	assert(cur_floor<=floor_count);
	static int no_of_passengers_removed = 0;
	int floor_index = cur_floor -1; //needed because floor array strt at 0 and elevator floor at 1
	struct passenger* temp;
	temp = floordetails[floor_index];
	floordetails[floor_index] = floordetails[floor_index]->next;
	printf("Passenger %d from floor %d is removed. No of passengers removed: %d\n",temp->id,cur_floor,++no_of_passengers_removed);
	free(temp);
		return 1;
}
