#include <stdio.h>
#include <stdbool.h>
#include "globals.h"
#include "structures.h"
#include "is_lift_on_floor.h"
#include "functions.h"
/**
Calls the function lift_on_floor.c with valid parameters.
Prints the PASS /FAIL status ,by accessing the  return from lift_on_floor function.
results_is_lift_on_floor file contains the results.
**/
void test_is_lift_on_floor(void)
{
	struct elevator ele[3];
	elevator_count = 3;
	FILE *fp;
	fp = fopen("test/results/results_is_lift_on_floor.txt", "w+");
	int arr = is_lift_on_floor(ele, 1);
	if (arr != 0)
	{
		fprintf(fp, "PASS;Input Parameter:Valid;is_lift_on_floor function is accesssed successfully .\n");
		printf("PASS;Input Parameter:Valid;is_lift_on_floor function is accesssed successfully .\n");
	}
	else
	{
		fprintf(fp, "FAIL;Input Parameter:Valid;is_lift_on_floor function cannot be accesssed  .\n");
		printf("PASS;Input Parameter:Valid;is_lift_on_floor function is accesssed successfully .\n");
	}
	fflush(fp);
	fclose(fp);
}
