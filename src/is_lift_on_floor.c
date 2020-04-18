#include<stdio.h>
#include"globals.h"
#include"structures.h"
#include"is_lift_on_floor.h"
/**
Reads the elevator structure's attribute between_floors.

Checks if the input parameter index(i.e)elevator number;is within the range of number of elevators in building.

If index is greater than the number of elevators actually present in building;error message will be displayed and returns -1. 

Checks the condition of the lift .

Return 0 if its not on floor(i.e)between_floors is 1.

Return 1 if its  on floor(i.e)between_floors is 0.

**/


int is_lift_on_floor(struct elevator elev[] ,int index )
{
	if(index >= elevator_count)//check on the input parameter which cannot be more than the number of elevators in the building.
	{
        fprintf(stderr, "Input parameter -Index is greater than the array ele[]-------- %d >= %d \n",index, elevator_count);
        exit();
		return -1;
    }
	
	if(elev[index].between_floor==1)//check on the value of between_floors that makes evident if the lift is on floor or in between.
	{
		return 0;
	}
	else if(elev[index].between_floor==0)
	{
		return 1;
	}
	
}


