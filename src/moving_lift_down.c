#include <stdio.h>
#include <stdbool.h>
#include "structures.h"
#include "globals.h"
#include "moving_lift_down.h"


int moving_lift_down(struct elevator elevator_arr[], unsigned int index){

    if(index >= elevator_count){
        fprintf(stderr, "index >= elevator_arr size. %d >= %d \n",index, elevator_count);
        return -1;
    }
    elevator_arr[index].direction_up = false;
    elevator_arr[index].direction_down = true;
    return 1;
}