/**
 *  @file test_remove_passenger_floor.c
 * 
 *  @brief contains tests for remove_passenger_floor
 * 
 *  @author Maaz Jamal
 *  */

#include "remove_passenger_floor.h"
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "globals.h"

/**
 * @brief tests the remove_passenger function.
 * 
 *  Tests the removal of two passengers from a floor. The first removal causes the floor to contain 
 *  the second passenger at start. the second removal replaces the passenger with NULL pointer.
 * @return void does not return anything
 * */

void test_remove_passenger_floor(void){
floor_count = 3;
struct passenger** floors =(struct passenger**) calloc(3,sizeof(struct passenger*));
struct passenger dummy1 = {0, 0, 0, 0, 10, 0};
struct passenger dummy2 = {0, 0, 0, 0, 20, 0};
FILE *f = fopen("test/results/results_remove_passenger_floor.txt", "w+");
floors[1] =(struct passenger*) malloc(sizeof(struct passenger));
*(floors[1]) = dummy1;
floors[1]->next = (struct passenger*) malloc(sizeof(struct passenger));
*(floors[1]->next) = dummy2;
remove_passenger_floor(floors,2);
if(floors[1]->id == dummy2.id){
	fprintf(f,"PASS: Removed 1st Passenger. Id on floor is %d\n", dummy2.id);
	printf("PASS: Removed 1st Passenger. Id on floor is %d\n", dummy2.id);
}
else{
	fprintf(f,"FAIL: Expected Passenger.Id %d Got : %d\n", dummy2.id,floors[1]->id);
	printf("FAIL: Expected Passenger.Id %d Got : %d\n", dummy2.id,floors[1]->id);

}
remove_passenger_floor(floors,2);
if(floors[1] == NULL){
	fprintf(f,"PASS: Removed 2nd Passenger. Pointing to NULL %p\n", floors[1]);
	printf("PASS: Removed 2nd Passenger. Pointing to NULL %p\n", floors[1]);
}
else{
	fprintf(f,"FAIL: Expected floor point to NULL.Instead Got : %p\n", floors[1]);
	printf("FAIL: Expected floor point to NULL.Instead Got : %p\n", floors[1]);	
}
fflush(f);
fclose(f);

}
