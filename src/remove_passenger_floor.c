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
	assert(cur_floor<floor_count);
	
	struct passenger* temp;
	temp = floordetails[cur_floor];
	floordetails[cur_floor] = floordetails[cur_floor]->next;
	free(temp);
	printf("Passenger details for floor %d is removed\n",cur_floor);
	return 1;
}
