#include<stdio.h>
#include<stdlib.h>
#include"structures.h"
#include"create_elevator_array.h"
#include"globals.h"

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
	
	if((no_of_elevators==0)||(no_of_elevators>100)||(no_of_elevators<1))//checks if the input parameter is valid.
	{
		printf("Input parameter -Number of elevators entered is invalid \n");
		return 0;
	}
	struct elevator *ele;
	ele=malloc (no_of_elevators * sizeof(struct elevator));//creates memory for the input-no_of_elevators.
	if(ele==NULL)//checks if the memory allocation is success
	{
		printf("Memory allocation failed \n");
		return 0;
	}
	else
	{
		
		int i;
		int j;
		int k;
		for(i=0;i<no_of_elevators;i++)//initialising the array elements
		{
			ele[i].moving=0;
			ele[i].between_floor=0;
			ele[i].direction_up=true;
			ele[i].direction_down=false;
			ele[i].stop_at_floor=malloc(floor_count*sizeof(bool));
			for(k=0;k<floor_count;k++)
			{
				ele[i].stop_at_floor[k]=0;
			}
			ele[i].passenger_count=0;
			ele[i].max_passenger=10;
			ele[i].cur_floor=1;
			ele[i].timer=0;
			ele[i].passenger_arr = malloc(ele[i].max_passenger*sizeof(struct passenger));
			for (j=0;j<ele[i].max_passenger;j++)
			{
			ele[i].passenger_arr[j].in_elevator=0;
			ele[i].passenger_arr[j].arrival_time=0;
			ele[i].passenger_arr[j].arrival_floor=0;
			ele[i].passenger_arr[j].dest_floor=0;
			ele[i].passenger_arr[j].id=0;
			}
			
		}
	
	return ele;
	}
	
}

