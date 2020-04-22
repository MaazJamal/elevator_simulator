#include <stdio.h>
#include <stdlib.h>
#include "../include/globals.h"
#include "../include/structures.h"
#include "../include/is_lift_empty.h"

/**
 * @file test_is_lift_empty.c
 *
 * @author Ritika Arora
 *
 * @brief Tests if the is_lift_empty function works fine or not
 *
 * @detail The function tests with different values if the output comes correct or not.
 * elevator_count which is a global variable has been set to a fix value
 * The test cases are as below:
 * - For array with passenger count equal to the maximum number of passengers of the lift,
 * 		and index value as 0 or less than the elevator count
 * 		the output is 0
 * - For array with passenger count less than the maximum number of passengers of the lift,
 * 		and index value as 1 or less than the elevator count
 * 		the output is 1
 * - For array with passenger count more than the maximum number of passengers of the lift,
 * 		and index value as 2 or less than the elevator count
 * 		the output is 0
 * - For array with index value as 3 or greater than or equal to the elevator count
 * 		the output is -1
 * - For an empty array, the output is -1 and the program exits
 *
 * @param[in] The function takes no input
 *
 * @return void The function returns nothing.
*/

void test_is_lift_empty(){

	FILE* test_results = fopen("test/results/results_is_lift_empty.txt", "w+");
	struct elevator elevator_array[3];
	struct elevator *ele_arr = NULL;
	struct elevator values = { 0 };
	elevator_array[0] = values;

	elevator_array[1].passenger_count = 5;
	elevator_array[1].max_passenger = 10;

	elevator_array[2].passenger_count = 15;
	elevator_array[2].max_passenger = 10;

	elevator_count = 3;

	int result;

	result = is_lift_empty(elevator_array,0);

	if (result == 0){
	      char temp[100];
	      sprintf(temp,"PASS: Input: Elevator with passengers equal to the maximum passenger,"
	              " Expected Output: 0,"
	              " Output: %d .\n",result);
	      printf(temp);
	      fprintf(test_results,temp);
	}
	else{
	      char temp[100];
	      sprintf(temp,"FAIL: Input: Elevator with passengers equal to the maximum passenger,"
	              " Expected Output: 0,"
	              " Output: %d .\n",result);
	      printf(temp);
	      fprintf(test_results,temp);
	}


	result = is_lift_empty(elevator_array,1);

	if (result == 1){
        char temp[100];
        sprintf(temp,"PASS: Input: Elevator with passengers less than the maximum passenger,"
                " Expected Output: 1,"
                " Output: %d .\n",result);
        printf(temp);
        fprintf(test_results,temp);
	}
	else{
        char temp[100];
        sprintf(temp,"FAIL: Input: Elevator with passengers less than the maximum passenger,"
                " Expected Output: 1,"
                " Output: %d .\n",result);
        printf(temp);
        fprintf(test_results,temp);
	}

    result = is_lift_empty(elevator_array,2);

	if (result == 0){
        char temp[100];
        sprintf(temp,"PASS: Input: Elevator with passengers more than the maximum passenger,"
                " Expected Output: 0,"
                " Output: %d .\n",result);
        printf(temp);
        fprintf(test_results,temp);
	}
	else{
        char temp[100];
        sprintf(temp,"FAIL: Input: Elevator with passengers more than the maximum passenger,"
                " Expected Output: 0,"
                " Output: %d .\n",result);
        printf(temp);
        fprintf(test_results,temp);
	}



	result = is_lift_empty(elevator_array,3);

	if(result == -1){
        char temp[100];
        sprintf(temp,"PASS: Input: The index is greater than the elevators in the building,"
                " Expected Output: -1,"
                " Output: %d .\n",result);
        printf(temp);
        fprintf(test_results,temp);
	}
	else{
        char temp[100];
        sprintf(temp,"FAIL: Input: The index is greater than the elevators in the building,"
                " Expected Output: -1,"
                " Output: %d .\n",result);
        printf(temp);
        fprintf(test_results,temp);
	}


    result = is_lift_empty(ele_arr,4);

    if(result == -1){
		if(ele_arr == NULL){
			char temp[100];
			char *output = "There is no elevator!";
			sprintf(temp,"PASS: Input: Empty elevator array,"
					" Expected Output: Exit program after printing: There is no elevator!,"
					" Output: %s .\n",output);
			printf(temp);
			fprintf(test_results,temp);
			exit(1);
		}
		else{
			char temp[100];
			char *output = "There is some problem!";
			sprintf(temp,"FAIL: Input: Empty elevator array,"
					" Expected Output: Exit program after printing: There is no elevator!,"
					" Output: %s .\n",output);
			printf(temp);
			fprintf(test_results,temp);
			exit(1);
		}
    }



}
