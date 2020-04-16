#include <stdio.h>
#include "../include/globals.h"
#include "../include/is_lift_empty.h"

/*
*@brief Checks if there is any space in the elevator to add more passengers
*
*@detail The function is to check if the elevator has any space to accommodate any
* other passenger or not.
* Firstly, it checks if the elevator number entered is less than the total
* number of elevators in the building.
* If it is greater than the total number of elevators in the building
* then it will give the error message and will return -1
* Then, it checks if the number of the passengers in the elevator is
* more than or equal to the max number of passengers it can accommodate,
* then it prints that the lift is full and returns 0.
* Else, it returns 1.
*
* @return integer Returns -1 if errors in input and 1 if it has any space
* for any passenger and 0 if not.
*/
unsigned int elevator_count; //definition of the global variable
int is_lift_empty(struct elevator elevator_arr[], unsigned int index){
    int has_space;
    if(index >= elevator_count){
        fprintf(stderr, "Index is greater than the elevator_arr size. %d >= %d \n",index, elevator_count);
        return -1;
    }
    if(elevator_arr[index].passenger_count >= elevator_arr[index].max_passenger){
        fprintf(stdout, "The lift is full!! Can't add more passengers.");
        has_space = 0;
    }
    else{
        has_space = 1;
    }
    return has_space;
}
