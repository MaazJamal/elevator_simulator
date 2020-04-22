#include <stdio.h>
#include "../include/globals.h"
#include "../include/max_waiting_time.h"

/**
 * @file test_max_waiting_time.c
 *
 * @author Ritika Arora
 *
 * @brief tests the  max_waiting_time function if working fine or not
 *
 * @detail The function is to test max_waiting_time function for given inputs, the function
 * returns right values or not. The max_waiting_time function is called with different inputs
 * and its output is stored in one local variable. The max_time local variable should give the
 * maximum of all the inputs given.
 * The function checks if the max_time stores maximum of the inputs given to the max_waiting_time
 * function , then the test passes and prints the result on console as well as writes on a file.
 *
 * @param[in] No input is given to the function
 *
 * @return void The function returns nothing.
*/

void test_max_waiting_time(void)
{

	FILE *test_results = fopen("test/results/results_max_waiting_time.txt", "w+");

	float time1 = 120;
	float time2 = 249;
	float time3 = 300;
	float time4 = 130;
	float max_time;
	max_time = max_waiting_time(time1);
	max_time = max_waiting_time(time2);
	max_time = max_waiting_time(time3);
	max_time = max_waiting_time(time4);
	if (max_time == 300)
	{
		char result[100];
		sprintf(result, "PASS: Input: 120, 249, 300, 130, Expected Output: 300, Output: %f .\n", max_time);
		printf(result);
		fprintf(test_results, result);
	}
	else
	{
		char result[100];
		sprintf(result, "FAIL: Input: 120, 249, 300, 130, Expected Output: 300, Output: %f .\n", max_time);
		printf(result);
		fprintf(test_results, result);
	}
}
