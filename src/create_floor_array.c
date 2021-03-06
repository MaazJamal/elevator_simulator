/**
 * @file create_floor_array.c
 *
 * @brief The function create arrays for every floor
 *
 * @author Hariprasad Munusamy  - HariprasadMunusamy@cmail.carleton.ca	
 *
 */
 
#include<stdio.h>
#include<stdlib.h>
#include "create_floor_array.h"
#include "globals.h"
#include "structures.h"

/** @details Creates array for every floor to store the passenger with requests.
 *
 * @param[in] Gets the number of floors as input and creates a list of array for every floor.
 *
 * @return structure of arrays for the given number of floors.
 *
 */
 
 struct passenger ** create_floor_array(int no_of_floors)
 {
    if(no_of_floors>floor_count)
	{
		return 0;
	}
	struct passenger **fla;
	fla=(struct passenger **) calloc (no_of_floors,sizeof(struct passenger*));
	if(fla==NULL)
	{
		return 0;
	}
	else
	{

	return fla; //returns the pointer to a structure of array
	}

}
