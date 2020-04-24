/** @file test_add_passenger_floor.c
 * 
 * @brief provides blackbox unit testing for add_passenenger_floor function
 * 
 * @author Maaz Jamal
 * */

#include "add_passenger_floor.h"
#include <stdio.h>
#include <stdlib.h>
#include <structures.h>
#include <globals.h>

static void case1(void);
static void case2(void);

/** 
 * @brief tests two conditions for add_passenger_floor function.
 * 
 *  The two test cases are adding to an empty floor.
 *  Adding to a floor already with an added passenger. The new passenger is added
 * 	to the end of the floor list.
 * 	
 * 
 * */

struct passenger **floor_arr = NULL;
struct passenger add_passenger_dummy1 = {0, 0, 0, 0, 10, 0};
struct passenger add_passenger_dummy2 = {0, 0, 0, 0, 20, 0};
FILE *f;
void test_add_passenger_floor()
{
	f = fopen("test/results/results_test_add_passenger_floor.txt", "w+");
	floor_arr = (struct passenger **)calloc(3, sizeof(struct passenger *));
	floor_count = 3;
	case1();
	case2();
	fclose(f);
}

/**
 *  Tests the case of adding to a floor with no previous 
 *  passengers.
 * 
 * */
void case1(void)
{

	add_passenger_floor(floor_arr, 1, add_passenger_dummy1);
	if (floor_arr[1] != NULL)
	{
		printf("PASS Floor no longer points to null");
		fprintf(f, "PASS Floor no longer points to null");
		if (add_passenger_dummy1.id == floor_arr[1]->id)
		{
			fprintf(f, "PASS 1 PASSENGER ADDED SUCCESFULLY TO THE FLOOR LIST.\n");
			printf("PASS 1 PASSENGER ADDED SUCCESFULLY TO THE FLOOR LIST.\n");
		}

		else
		{
			fprintf(f, "FAIL: expected passenger id %d on floor instead got %d\n", add_passenger_dummy1.id, floor_arr[1]->id);
			printf("FAIL: expected passenger id %d on floor instead got %d\n", add_passenger_dummy1.id, floor_arr[1]->id);
		}
	}
	else
	{
		fprintf(f,"Fail Expected floor[1] to point to a passenger. Got %p", &floor_arr[1]);
		printf("Fail Expected floor[1] to point to a passenger. Got %p", &floor_arr[1]);
	}
	fflush(f);
}
/**
 * Test the case of adding to the passenger floor
 * with another passenger already on the floor.
 * 
 * */
void case2(void)
{
	add_passenger_floor(floor_arr, 0, add_passenger_dummy1);
	add_passenger_floor(floor_arr, 0, add_passenger_dummy2);
	if (floor_arr[0] != NULL)
	{
		fprintf(f, "PASS Floor no longer points to null");
		printf("PASS Floor no longer points to null");
		if (add_passenger_dummy1.id == floor_arr[0]->id)
		{
			fprintf(f, "PASS 1 PASSENGER ADDED SUCCESFULLY TO THE FLOOR LIST.\n");
			printf("PASS 1 PASSENGER ADDED SUCCESFULLY TO THE FLOOR LIST.\n");
		}

		else
		{
			fprintf(f, "FAIL: expected passenger id %d on floor instead got %d\n", add_passenger_dummy1.id, floor_arr[0]->id);
			printf("FAIL: expected passenger id %d on floor instead got %d\n", add_passenger_dummy1.id, floor_arr[0]->id);
		}
		if (add_passenger_dummy2.id == floor_arr[0]->next->id)
		{
			fprintf(f, "PASS: Second passenger added to the list.\n");
			printf("PASS: Second passenger added to the list.\n");
		}
		else
		{
			fprintf(f, "FAIL: expected second passenger id %d on floor instead got %d\n", add_passenger_dummy2.id, floor_arr[0]->next->id);
			printf("FAIL: expected second passenger id %d on floor instead got %d\n", add_passenger_dummy2.id, floor_arr[0]->next->id);
		}
	}
	else
	{
		fprintf(f, "Fail Expected floor[1] to point to a passenger. Got %p", floor_arr[1]);
		printf("Fail Expected floor[1] to point to a passenger. Got %p", floor_arr[1]);
	}
	fflush(f);
}