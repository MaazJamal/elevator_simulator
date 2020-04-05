#include <stdio.h>
#include <stdbool.h>
#include "../include/globals.h"
#include "../include/structures.h"
#include "../include/moving_lift_up.h"

/*
 * @brief To set the direction of the lift to Upward direction
 *
 * @detail The function is to set the direction of the lift to UP. The function calls with two
 * parameters: an array of elevators of elevator type and an integer value which indicated the
 * index as well as the number of the elevator in the building. The function firstly checks, if
 * the elevator number entered is less than the total number of elevators in the building. If
 * it is greater than the total number of elevators in the building then it will give the error
 *  message and will return -1
 * Otherwise, it will set the direction of that particular elevator to UP.
 * @returns integer value 1 if everything goes well.
 */

int moving_lift_up(struct elevator elevator_arr[], unsigned int index){

    if(index >= elevator_count){
        fprintf(stderr, "Index is greater than the elevator_arr size. %d >= %d \n",index, elevator_count);
        return -1;
    }
    elevator_arr[index].direction_up = true;
    elevator_arr[index].direction_down = false;
    return 1;
}
