#include <stdio.h>
#include "../include/globals.h"
#include "../include/max_waiting_time.h"


void test_max_waiting_time (){

    FILE* test_results = fopen("R:\\Ritz\\elevator_simulator\\test\\results\\results_inputs_lifts.txt", "w+");

	float time1 = 120;
	float time2 = 249;
	float time3 = 300;
	float time4 = 130;
	float max_time;
	max_time = max_waiting_time(time1);
	max_time = max_waiting_time(time2);
	max_time = max_waiting_time(time3);
	max_time = max_waiting_time(time4);
	if(max_time == 300){
		char result[100];
        sprintf(result,"PASS: Input: 120, 249, 300, 130, Expected Output: 300, Output: %f .\n",max_time);
        printf(result);
        fprintf(test_results,result);
	}
	else{
		char result[100];
        sprintf(result,"FAIL: Input: 120, 249, 300, 130, Expected Output: 300, Output: %f .\n",max_time);
        printf(result);
        fprintf(test_results,result);
	}
}



