#include "cli_update.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Updates the command line interface with the elevator data.
 * 
 * Clears the screen and repopulates it with the updated elevator data.
 * @param [in] arr struct elevator that is an array of elevators.
 * @return  
 *  */
void cli_update(struct elevator arr[],unsigned int loop_time)
{

/** Checks if we are in unix/cygwin environment or windows environment
	 * */
#if __unix__ || __CYGWIN__
	system("clear");
#elif _WIN32
	system("cls");
#endif
	puts("Elevator\tTime\tFloor\tPassengers\tDirection\tMoving\t");
	int current_floor = 0;
	int passenger = 0;
	bool direction_down = false;
	bool direction_up = false;
	int next_floor_time = 0;
	bool moving = false;
	char direction[5] = {'\0','\0','\0','\0','\0'};
	char move_or_no[4] = {'\0','\0','\0','\0',};
	for (int i = 0; i < elevator_count; i++)
	{
		current_floor = arr[i].cur_floor;
		passenger = arr[i].passenger_count;
		direction_down = arr[i].direction_down;
		direction_up = arr[i].direction_up;
		next_floor_time = arr[i].timer;
		moving = arr[i].moving;
		if (direction_up)
		{
			strcpy(direction, "UP");
		}
		else if (direction_down)
		{
			strcpy(direction, "DOWN");
		}
		else
		{
			strcpy(direction, "ANY");
		}
		if (moving)
		{
			strcpy(move_or_no, "YES");
		}
		else
		{
			strcpy(move_or_no, "NO");
		}
		printf("%d\t\t%d\t%d\t%d\t\t%s\t\t%s\n", i, next_floor_time, current_floor, passenger, direction, move_or_no);
	}
	printf("SIMULATION TIME: %d\n",loop_time);
}