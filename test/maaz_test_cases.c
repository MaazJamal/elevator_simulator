/** @file maaz_test_cases.c
 * file that test all the functions developed by maaz
 * **/

//test to see if functions can be included and header guards are working
#include "input_lifts.h"
#include "remove_passenger_queue.h"
#include "structures.h"
#include "add_request_queue.h"
#include "moving_lift_down.h"
#include <stdio.h>
#include <string.h>

extern void test_input_lifts(void);
extern void test_moving_lift_down(void);

int main(void){
    
    printf("Testing All functions.\n");
    test_input_lifts();
    test_moving_lift_down();
    
    return 1;
}




