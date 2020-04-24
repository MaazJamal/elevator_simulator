#include <stdio.h>
#include "input_floors.h"

/**
 * @file input_floors.c
 *
 * @brief Obtains the floor count-Total number of floors in the building.Enables the user to enter the total number of floors in the building.
 * based on availability. If none of those symptoms then patient is not admitted.
 *
 * @author Divyalakshmi Padmanaban  - Dpadm049@uottawa.ca
 *
 */
/** @details Constraints
 *If the floor count is 0 ,the function displays a error message and returns -1.
 *If the floor count is less than 1(negative values) ,the function displays a error message and returns -1.
 *If the floor count is greater than 100,the function displays a error message and returns -1.
 *Floating point values entered considered to near integers.
 * @return The function accepts only values between 1 and 100 and returns the value;otherwise returns -1 and displays error message.
 */
int input_floors(void)
{
	int local_floor_count;

	printf("Enter the number of floors in the building-VALID INPUTS ARE FROM 1 TO 100\n");
	puts("This Value should be greater than or equal to maximum floor number in input.txt file.");
	scanf("%d", &local_floor_count);
	//Following checks are performed to see if the entered value is erraneous.
	if (local_floor_count == 0)
	{
		printf("Entered number of floor invalid \n");
		local_floor_count = -1;
	}
	else if (local_floor_count < 1)
	{
		printf("Entered number of floor is negative value and hence invalid \n");
		local_floor_count = -1;
	}
	else if (local_floor_count > 100)
	{
		printf("Entered number of floor is greater than 100 and hence invalid \n");
		local_floor_count = -1;
	}
	//discards the values stored in stdin buffer.
	scanf("%*[^\n]");
	return local_floor_count;
}
