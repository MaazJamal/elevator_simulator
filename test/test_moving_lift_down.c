#include "moving_lift_down.h"
#include <stdio.h>
#include "structures.h"
#include "globals.h" 
#include "stdlib.h"

// struct elevator{
// bool	moving; //! Is the elevator moving? True 1 or False(stationary) 0.
// bool	between_floor; //! Is elevator between floors. True 1 between floors.
// bool	direction_up; //! Is the elevator going up? True 1 for going up
// bool	direction_down; //! Is the elevator going down? True 1 for going down
// bool    *stop_at_floor; //! points to boolean array of floors and shows if the elevator will stop at a certain floor or not.
// unsigned int	passenger_count; //! count of passenger occupying the elevator
// unsigned int	max_passenger; //! Maximum number of passengers the lift can accomodate
// unsigned int	cur_floor; //!
// unsigned int 	timer; //! Time clock untill the next floor
// struct passenger *passenger_arr; //! points to a array of struct pasenger of size max_passenger.   
// };

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

