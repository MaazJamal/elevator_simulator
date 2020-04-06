#include<stdio.h>
#include"input_floors.h"

/**
Obtains the floor count-Total number of floors in the building

Enables the user to enter the total number of floors in the building .

Constraints
If the floor count is 0 ,the function displays a error message and returns -1.
If the floor count is less than 1(negative values) ,the function displays a error message and returns -1.
If the floor count is greater than 100,the function displays a error message and returns -1.
Floating point values entered considered to near integers.
The function accepts only values between 1 and 100 and returns the value;otherwise returns -1 and displays error message.

**/
int input_floors(void)

{
	int floor_count;

	printf("Enter the number of floors in the building-VALID INPUTS ARE FROM 1 TO 100");
    scanf("%d",&floor_count);
    //Following checks are performed to see if the entered value is erraneous.
	if(floor_count==0)
	{
		printf("Entered number of floor is 0 and hence  invalid ");
		floor_count = -1;
	}
    if(floor_count<1)
	{
		printf("Entered number of floor is negative value and hence invalid ");
		floor_count=-1;
	}
	if(floor_count>100)
	{
		printf("Entered number of floor is greater than 100 and hence invalid ");
		floor_count=-1;
	}
	return floor_count;	
}
