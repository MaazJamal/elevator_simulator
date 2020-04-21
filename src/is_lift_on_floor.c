#include<stdio.h>
#include"globals.h"
#include"structures.h"
#include"is_lift_on_floor.h"
#include<stdlib.h>
/**
 * @file is_lift_on_floor.c
 *
 * @brief Reads the elevator structure's attribute between_floors.
 *
 * @author Divyalakshmi Padmanaban  - Dpadm049@uottawa.ca
 *
 */
/**@ details Constraints
 *Checks if the input parameter index(i.e)elevator number;is within the range of number of elevators in building.
 *If index is greater than the number of elevators actually present in building;error message will be displayed and returns -1. 
 *Checks the condition of the lift .
 * @param[in] The function takes the elevator structure and index. 
 *@ return The function 0 if lift is not on floor elso 0.
*/ 

int is_lift_on_floor(struct elevator elev[] ,int index )
{
	if(index >= elevator_count)//check on the input parameter which cannot be more than the number of elevators in the building.
	{
        fprintf(stderr, "Input parameter -Index is greater than the array ele[]-------- %d >= %d \n",index, elevator_count);
        exit(1);
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
	else{
		fprintf(stderr, "Incorrect elev[index].between_floor Value : %d \n",elev[index].between_floor);
        exit(1);
	}
}


