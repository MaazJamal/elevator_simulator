#include <stdio.h>
#include <stdbool.h>
#include "structures.h"
#include "globals.h"
#include "moving_lift_down.h"


void moving_lift_down(struct elevator *elevator_arr, unsigned int index){

    if(index >= elevator_count){
        fprintf(stderr, "index >= elevator_arr size. %d >= %d ",index,1);
        return;
    }
    elevator_arr[index].direction_up = false;
    elevator_arr[index].direction_down = true;
    return ;
}