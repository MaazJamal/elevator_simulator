/** @file test_create_elevator_array.c
 * 
 * @brief Contains test cases for create_elevator_array() function.
 * 
 * */



#include <stdio.h>
#include <stdbool.h>
#include "structures.h"
#include "create_elevator_array.h"
#include "functions.h"

/**
Calls the function create_elevator_array.c with valid parameters.
Prints the PASS /FAIL status ,by accessing the  return from create_elevator_array function.
results_create_elevator_array file contains the results.
**/
void test_create_elevator_array(void)
{
	struct elevator *elev;
	printf("results_create_elevator_array file contains output \n\n ");
	FILE *fp;
	fp = freopen("test/results/results_create_elevator_array.txt", "w+", stdout);
	elev = create_elevator_array(4);
	if (elev != NULL)
	{
		printf("PASS;Input Parameter:Valid;array of structure elevator could be accessed .\n");
	}
	else
	{
		printf("FAIL;Input Parameter:Valid;array of structure elevator could not be accessed .\n");
	}
	fflush(fp);
	fclose(fp);
}
