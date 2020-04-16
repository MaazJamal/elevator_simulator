
/**@file remove_passenger_floor.h 
the function  defination  found in remove_passenger_floor.c 
Removes the passenger details from floor specified.

Constraints
The program terminates if the input parameter cur_floor(passenger details for this particular floor has to be deleted)is erraneous.
(i.e)cur_floor must be within the range 1-100 and less than the floor_count(Total number of floors in the building )

Returns 1 on successful deletion of passenger details from specified floor.
**/
#ifndef __REMOVE_PASSENGER_FLOOR_H__
#define __REMOVE_PASSENGER_FLOOR_H__
#include "structures.h"

extern remove_passenger_floor(struct passenger* floor[], int cur_floor);

#endif
