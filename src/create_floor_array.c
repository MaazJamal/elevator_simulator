#include<stdio.h>
#include<stdlib.h>
#include "create_floor_array.h"
/**
 * The function create arrays for every floor
 *
 * Gets the number of floors as input and creates a list of array for every floor.
 *
 * @return structure of arrays for the given number of floors.
 *  */
 struct passenger * create_floor_array(int no_of_floors)
 {
    if(no_of_floors>floor_count)
	{
		return 0;
	}
	struct floor *fla;
	fla=malloc (no_of_floors * sizeof(struct passenger));
	if(fla==NULL)
	{
		return 0;
	}
	else
	{

	return fla; //returns the pointer to a structure of array
	}

}
