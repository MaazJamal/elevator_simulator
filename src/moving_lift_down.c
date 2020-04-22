/**
 * @file moving_lift_down.c
 * @brief contains the definition of moving_lift_down
 * 
 * @author Maaz Jamal
 * 
 * */

#include <stdio.h>
#include <stdbool.h>
#include "structures.h"
#include "globals.h"
#include "moving_lift_down.h"

/**
 * @brief changes the direction of lift to down.
 * 
 * This function takes as input an elevator array and changes the direction of the elevator
 * at the specified index position. sets elevator.direction_up to false
 * and elevator.direction_down to true.
 * @param[in, out] elevator_arr[] an array of type struct elevator 
 * @return int Returns -1 if errors in function call and 1 if function runs properly. 
 *  */

int moving_lift_down(struct elevator elevator_arr[], unsigned int index)
{

    if (index >= elevator_count)
    {
        fprintf(stderr, "index >= elevator_arr size. %d >= %d \n", index, elevator_count);
        return -1;
    }
    elevator_arr[index].direction_up = false;
    elevator_arr[index].direction_down = true;
    return 1;
}