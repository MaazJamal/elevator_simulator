#include "moving_lift_down.h"
#include <stdio.h>
#include "structures.h"
#include "globals.h" 
#include "stdlib.h"

/** @brief This function test the function moving_lift_down.
 * 
 * Function tests array out of bounds check. Change elevator direction test.
 * 
 * */ 

void test_moving_lift_down(void){
	struct elevator arr[3];
	struct elevator temp =  {0,0,0,0,0,0,0,0,0,0};
	FILE *test_results = fopen("test/results/test_moving_lift_down.txt","w");
	arr[1] = temp;
	arr[2] = temp;
	arr[0] = temp;
	
	elevator_count = 3;
	char * pass = "PASS:";
	char * fail = "FAIL:";

	int result = moving_lift_down(arr, 3);

	if(result == -1){
		char temp[100];
        sprintf(temp,"%s: Function returned %d Expected -1 . Array out of bound check working.\n",
                pass,result );
        printf(temp);
        fprintf(test_results,temp);
	}
	else {
		char temp[100];
        sprintf(temp,"%s: Array values properly changed: direction_up = %d .\
						direction_down = %d, Return = %d\n",
                fail,arr[2].direction_up, arr[2].direction_down, result);
        printf(temp);
        fprintf(test_results,temp);
	}



	result = moving_lift_down(arr, 2);
	if(result != -1){
	result = arr[2].direction_up == 0 && arr[2].direction_down == 1;
	}
	if(result == -1){
		char temp[100];
        sprintf(temp,"%s: Function returned %d Expected 1.\n",
                fail,result );
        printf(temp);
        fprintf(test_results,temp);
	}
	else {
		char temp[100];
        sprintf(temp,"%s: Array values properly changed: direction_up = %d .\
						direction_down = %d, Return = %d\n",
                pass,arr[2].direction_up, arr[2].direction_down, result);
        printf(temp);
        fprintf(test_results,temp);
	} 

	result = arr[1].direction_up == 0 && arr[1].direction_down == 0;
	if(result == 1){
		char temp[100];
        sprintf(temp,"%s: Rest of Array Unchanged direction_up = %d ."
						"direction_down = %d\n",
                pass,arr[1].direction_up, arr[1].direction_down);
        printf(temp);
        fprintf(test_results,temp);
	}

	//Reapeat the tests but with ptr to a dynamicall allovated array
	
	struct elevator* ptr_arr = malloc(sizeof(struct elevator)*3);

	result = moving_lift_down(ptr_arr, 3);
	if(result == -1){
		char temp[100];
        sprintf(temp,"%s: Pointer: Function returned %d Expected -1 . Array out of bound check working.\n",
                pass,result );
        printf(temp);
        fprintf(test_results,temp);
	}
	else {
		char temp[100];
        sprintf(temp,"%s: Pointer: Array values properly changed: direction_up = %d .\
						direction_down = %d, Return = %d\n",
                fail,ptr_arr[2].direction_up, ptr_arr[2].direction_down, result);
        printf(temp);
        fprintf(test_results,temp);
	}



	result = moving_lift_down(ptr_arr, 2);
	if(result != -1){
	result = ptr_arr[2].direction_up == 0 && ptr_arr[2].direction_down == 1;
	}
	if(result == -1){
		char temp[100];
        sprintf(temp,"%s: Pointer: Function returned %d Expected 1.\n",
                fail,result );
        printf(temp);
        fprintf(test_results,temp);
	}
	else {
		char temp[100];
        sprintf(temp,"%s: Pointer: Array values properly changed: direction_up = %d .\
						direction_down = %d, Return = %d\n",
                pass,ptr_arr[2].direction_up, ptr_arr[2].direction_down, result);
        printf(temp);
        fprintf(test_results,temp);
	} 

	result = ptr_arr[1].direction_up == 0 && ptr_arr[1].direction_down == 0;
	if(result == 1){
		char temp[100];
        sprintf(temp,"%s: Pointer: Rest of Array Unchanged direction_up = %d ."
						"direction_down = %d\n",
                pass,ptr_arr[1].direction_up, ptr_arr[1].direction_down);
        printf(temp);
        fprintf(test_results,temp);
	}
	fflush(test_results);
	fclose(test_results);
}

