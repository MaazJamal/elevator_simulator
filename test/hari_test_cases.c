/** @file hari_test_cases.c
 * file that test all the functions developed by hari
 * **/

//test to see if functions can be included and header guards are working
#include "count_passenger.h"
#include "create_floor_array.h"
#include "passengers_drop.h"
#include "structures.h"
#include "globals.h"
#include <stdio.h>
#include <string.h>

extern void test_count_passenger(void);

int main(void){
    
    printf("Testing Count passenger functions.\n");
    test_count_passenger();
    return 1;
}
