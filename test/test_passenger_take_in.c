/** @file test_passenger_take_in.c
 * @brief This file contains function test_passenger_take_in() that provides unit testing for function passenger_take_in().
 * @author Maaz Jamal
 * */

#include "passengers_take_in.h"
#include <stdio.h>
#include <stdlib.h>
#include "globals.h"
#include "structures.h"

static void case1(void);
static void case2(void);
static void case3(void);
static void case4(void);
static void case5(void);

struct elevator dummy = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
struct elevator dummy_2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
struct passenger dummy_pass = {1, 0, 0, 4, 0, 0};

FILE *f;

int test_passenger_take_in(void)
{
	f = fopen("test/results/test_passenger_take_in_result.txt", "w");
	printf("chose between the test cases:\n");
	puts("1- incorrect elevator array index the program should exit.");
	puts("2- incorrect floor array index the program should exit.");
	puts("3- mismatched elevator current floor and floor index");
	puts("4- add 3 passenger to 5 free spots from 3 passenger on floor");
	puts("4- add 5 passenger to 5 free spots from 7 passenger on floor");
	int a;
	scanf("%d", &a);
	switch (a)
	{
	case 1:
		case1();
		break;
	case 2:
		case2();
		break;
	case 3:
		case3();
		break;
	case 4:
		case4();
		case5();
		break;
	default:
		break;
	}
	fclose(f);
	return 0;
}

/** This function tests the condition of incorrect elevator index.
 * for incorrect index the function should cause an assert error.
 * @return void does not return anything.
 * */
void case1(void)
{
	elevator_count = 1;
	floor_count = 10;
	struct elevator *ell_arr = malloc(sizeof(struct elevator) * 2);
	ell_arr[0] = dummy;
	ell_arr[1] = dummy_2;
	struct passenger **floor_arr = malloc(sizeof(struct passenger *) * 10);
	passengers_take_in(ell_arr, 1, floor_arr, 1, 0);
}

/** This function tests the condition of incorrect floor index.
 * for incorrect index the function should cause an assert error.
 * @return void does not return anything.
 * */
void case2(void)
{
	elevator_count = 2;
	floor_count = 10;
	struct elevator *ell_arr = malloc(sizeof(struct elevator) * 2);
	ell_arr[0] = dummy;
	ell_arr[1] = dummy_2;
	struct passenger **floor_arr = malloc(sizeof(struct passenger *) * 10);
	passengers_take_in(ell_arr, 1, floor_arr, 10, 0);
}

/** This function tests the condition of incorrect current floor.
 * for incorrect current floor in elevator and floor index the function should cause an assert error.
 * @return void does not return anything.
 * */
void case3(void)
{
	elevator_count = 2;
	floor_count = 10;
	struct elevator *ell_arr = malloc(sizeof(struct elevator) * 2);
	ell_arr[0] = dummy;
	ell_arr[1] = dummy_2;
	struct passenger **floor_arr = malloc(sizeof(struct passenger *) * 10);
	ell_arr[1].cur_floor = 2;
	passengers_take_in(ell_arr, 1, floor_arr, 5, 0);
}

/** This function tests the condition of removing passenger from floor to elevator.
 * test if the three passengers are removed from the floor and added to the elevator
 * @return void does not return anything.
 * */
void case4(void)
{
	elevator_count = 2;
	floor_count = 10;
	struct elevator *ell_arr = malloc(sizeof(struct elevator) * 2);
	ell_arr[0] = dummy;
	ell_arr[1] = dummy_2;
	struct passenger **floor_arr = malloc(sizeof(struct passenger *) * 10);
	for (int i = 0; i < elevator_count; i++)
	{
		ell_arr[i].stop_at_floor = (bool *)calloc(10, sizeof(bool));
	}
	for (int i = 0; i < 10; i++)
	{
		floor_arr[i] = NULL;
	}
	struct passenger *one = malloc(sizeof(struct passenger));
	*one = dummy_pass;
	struct passenger *two = malloc(sizeof(struct passenger));
	*two = dummy_pass;
	struct passenger *three = malloc(sizeof(struct passenger));
	*three = dummy_pass;
	one->next = two;
	two->next = three;
	three->next = NULL;
	floor_arr[4] = one;
	one->in_elevator = false;
	two->in_elevator = false;
	three->in_elevator = false;

	for (int i = 0; i < 2; i++)
	{
		ell_arr[i].passenger_arr = malloc(sizeof(struct passenger) * 10);
		ell_arr[i].max_passenger = 10;
		ell_arr[i].passenger_count = 5;
		for (int j = 0; j < 10; j++)
		{
			ell_arr[i].passenger_arr[j] = dummy_pass;
			if (j % 2 == 0)
			{
				ell_arr[i].passenger_arr[j].in_elevator = false;
			}
		}
	}
	ell_arr[1].cur_floor = 5;
	int added = passengers_take_in(ell_arr, 1, floor_arr, 5, 0);
	int okay = 0;
	for (int i = 0; i < 10; i++)
	{
		if (ell_arr[1].passenger_arr[i].in_elevator == false)
		{
			okay++; //okay should equal to two as two spots will be free
		}
	}
	if (added == 3 && okay == 2)
	{
		printf("PASS 3 passengers added. \n");
		fprintf(f, "PASS 3 passengers added. \n");
	}
	else
	{
		fprintf(f, "FAIL: passenger not added properly addded:%d free space:%d\n", added, okay);
		fprintf(f, "FAIL: passenger not added properly addded:%d free space:%d\n", added, okay);
	}
	if (floor_arr[4] == NULL)
	{
		printf("PASS 3 passengers removed from floor. \n");
		fprintf(f, "PASS 3 passengers removed from floor. \n");
	}
	else
	{
		printf("FAIL: 3 passengers not removed from floor. \n");
		fprintf(f, "FAIL: 3 passengers not removed from floor. \n");
	}
	fflush(f);
}

/** This function tests the condition of removing passenger from floor with more passegner to elevator.
 * test if the five passengers are removed from the floor of seven and added to the elevator
 * @return void does not return anything.
 * */
void case5(void)
{
	elevator_count = 2;
	floor_count = 10;
	struct elevator *ell_arr = malloc(sizeof(struct elevator) * 2);
	ell_arr[0] = dummy;
	ell_arr[1] = dummy_2;
	struct passenger **floor_arr = malloc(sizeof(struct passenger *) * 10);
	for (int i = 0; i < elevator_count; i++)
	{
		ell_arr[i].stop_at_floor = (bool *)calloc(10, sizeof(bool));
	}
	for (int i = 0; i < 10; i++)
	{
		floor_arr[i] = NULL;
	}
	struct passenger *one = malloc(sizeof(struct passenger));
	*one = dummy_pass;
	struct passenger *two = malloc(sizeof(struct passenger));
	*two = dummy_pass;
	struct passenger *three = malloc(sizeof(struct passenger));
	*three = dummy_pass;
	struct passenger *four = malloc(sizeof(struct passenger));
	*four = dummy_pass;
	struct passenger *five = malloc(sizeof(struct passenger));
	*five = dummy_pass;
	struct passenger *six = malloc(sizeof(struct passenger));
	*six = dummy_pass;
	struct passenger *seven = malloc(sizeof(struct passenger));
	*seven = dummy_pass;

	one->next = two;
	two->next = three;
	three->next = four;
	four->next = five;
	five->next = six;
	six->next = seven;
	seven->next = NULL;
	floor_arr[4] = one;
	one->in_elevator = false;
	two->in_elevator = false;
	three->in_elevator = false;
	four->in_elevator = false;
	five->in_elevator = false;
	six->in_elevator = false;
	seven->in_elevator = false;

	for (int i = 0; i < 2; i++)
	{
		ell_arr[i].passenger_arr = malloc(sizeof(struct passenger) * 10);
		ell_arr[i].max_passenger = 10;
		ell_arr[i].passenger_count = 5;
		for (int j = 0; j < 10; j++)
		{
			ell_arr[i].passenger_arr[j] = dummy_pass;
			if (j % 2 == 0)
			{
				ell_arr[i].passenger_arr[j].in_elevator = false;
			}
		}
	}
	ell_arr[1].cur_floor = 5;
	int added = passengers_take_in(ell_arr, 1, floor_arr, 5, 0);
	int okay = 0;
	for (int i = 0; i < 10; i++)
	{
		if (ell_arr[1].passenger_arr[i].in_elevator == false)
		{
			okay++; //okay should equal to zero as two spots will be free
		}
	}
	if (added == 5 && okay == 0)
	{
		printf("PASS 5 passengers added. \n");
		fprintf(f, "PASS 5 passengers added. \n");
	}
	else
	{
		printf("FAIL: passenger not added properly addded:%d free space:%d\n", added, okay);
		fprintf(f, "FAIL: passenger not added properly addded:%d free space:%d\n", added, okay);
	}
	if (floor_arr[4] == six)
	{
		printf("PASS 5 passenger removed and six passenger is first on the floor now \n");
		fprintf(f, "PASS 5 passenger removed and six passenger is first on the floor now \n");
	}
	else
	{
		printf("FAIL: passenger not removed properly from floor should point to:%p points to %p\n", six, floor_arr[5]);
		fprintf(f, "FAIL: passenger not removed properly from floor should point to:%p points to %p\n", six, floor_arr[5]);
	}
	fflush(f);
}
