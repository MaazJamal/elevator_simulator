#include <stdio.h>
#include <stdlib.h>
#include "../include/globals.h"
#include "../include/structures.h"
//#include "../include/test_is_lift_empty.h"
#include "../include/is_lift_empty.h"
//#include "../src/is_lift_empty.c"

/**
 * @brief Tests if the is_lift_empty function works fine or not
 *
 * @detail
 *
 * @param[in] The function takes no input
 *
 * @return The function returns nothing.
*/

//unsigned int elevator_count = 1;
void test_is_lift_empty(){

	FILE* test_results = fopen("R:\\Ritz\\elevator_simulator\\test\\results\\results_is_lift_empty.txt", "w+");
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
        sprintf(temp,"FAIL: Input: Elevator with passengers less than the maximum passenger,"
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
