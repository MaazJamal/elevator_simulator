/**
 * @file test_create_floor_array.c
 *
 * @brief To test create_floor_array function which creates array for every floor.
 *
 *
 * @author Hariprasad Munusamy  - HariprasadMunusamy@cmail.carleton.ca
 * @return Writes the test case log in output file
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "functions.h"

struct passenger
{
	bool in_elevator;			//!< Stores whether passegner is in elevator.
	unsigned int arrival_time;	//!< stores arrival time of the passenger
	unsigned int arrival_floor; //!< stores the arrival_floor of the passenger
	unsigned int dest_floor;	//!< stores the destination floor of the passenger
	unsigned int id;			//!< stores the passenger_id of the passenger
	struct passenger *next;		//! stores address of the next node in case of creation of queues
} dummy;

static struct passenger **create_floor_array(int no_of_floors)
{
	//if(no_of_floors>floor_count)
	//{
	//	return 0;
	//}
	struct passenger **fla;
	fla = (struct passenger **)calloc(no_of_floors, sizeof(struct passenger *));
	if (fla == NULL)
	{
		return 0;
	}
	else
	{

		return fla; //returns the pointer to a structure of array
	}
}
void test_create_floor_array(void)
{
	FILE *test_results = fopen("test/results/results_create_floor_array.txt", "w");
	printf("Enter the floor count\n");
	int floor_count;
	scanf("%d", &floor_count);
	struct passenger **floor_array = create_floor_array(floor_count);
	if (floor_array != NULL)
	{
		char temp[100];
		sprintf(temp, "PASS: Array created successfully \n");
		printf(temp);
		fprintf(test_results, temp);
	}
}
