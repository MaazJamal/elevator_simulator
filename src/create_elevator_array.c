#include<stdio.h>
#include<stdlib.h>
#include"create_elevator_array.h"

/**
creates an array for elevators with respective to input entered by user.


Constraints

checks the input parameter-no of elevators .

No of elevators should be in range(1-100).

Prints error message if the no of elevators is out of range and if memory allocation fails.

Returns the array of elevators.

**/



struct elevator * create_elevator_array(int no_of_elevators)
{
	if((no_of_elevators==0)||(no_of_elevators>100)||(no_of_elevators<1))
	{
		printf("Input parameter -Number of elevators enetered is invalid ");
		return 0;
	}
	struct elevator *ele;
	ele=malloc (no_of_elevators * sizeof(struct elevator));
	if(ele==NULL)
	{
		printf("Memory allocation failed ");
		return 0;
	}
	else
	{
	
	return ele;
	}
	
}

