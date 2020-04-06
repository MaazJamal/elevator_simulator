#include<stdio.h>
#include"is_lift_on_floor.h"
/**
Reads the elevator structure's attribute between_floors.

Checks the condition of the lift .

Return 0 if its not on floor.

Return 1 if its  on floor.

**/


int is_lift_on_floor(struct elevator elev[] ,int index )
{
	
	if(elev[index].between_floors==1)
	{
		return 0;
	}
	else if(elev[index].between_floors==0)
	{
		return 1;
	}
	
}


