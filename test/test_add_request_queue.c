/** @file test_add_request_queue.c
 * @brief This file contains function test_add_request_queue() that provides unit testing for function add_request_queue().
 * 
 * @author Maaz Jamal
 * */
#include "add_request_queue.h"
#include "stdio.h"
#include "structures.h"
#include <stdbool.h>

static struct passenger create_dummy_passenger(int val);
static bool compare(struct passenger a, struct passenger b);

void test_add_request_queue()
{
	struct passenger dummy1 = create_dummy_passenger(1);
	struct passenger dummy2 = create_dummy_passenger(2);
	struct passenger dummy3 = create_dummy_passenger(3);
	struct passenger *head = NULL;
	struct passenger *returned_ptr = NULL;
	struct passenger *cur = NULL;

	FILE *f = fopen("test/results/test_add_request.txt", "w");

	// Adding to a NULL address;
	returned_ptr = add_request_queue(head, dummy1);
	//	test if returned pointer is pointing to new head
	if (returned_ptr != NULL)
	{
		printf("PASS: Addind to NULL, returning ptr is == to new head.\n");
		fprintf(f, "PASS: Addind to NULL, returning ptr is == to new head.\n");
	}
	else
	{
		printf("FAIL: Addind to NULL, returning ptr is != to head.\n");
		printf("FAIL: Addind to NULL, returning ptr = %p head = %p.\n", returned_ptr, head);
		fprintf(f, "FAIL: Addind to NULL, returning ptr is != to head.\n");
		fprintf(f, "FAIL: Addind to NULL, returning ptr = %p head = %p.\n", returned_ptr, head);
	}
	head = returned_ptr;
	if (compare(dummy1, *head))
	{
		printf("PASS: ADDING to NULL, values succesfully copied.\n");
		fprintf(f, "PASS: ADDING to NULL, values succesfully copied.\n");
	}
	else
	{
		printf("FAIL: ADDING to NULL, EXPECTED: %d %d %d %d %d \n.", dummy1.arrival_floor, dummy1.arrival_time, dummy1.dest_floor, dummy1.id, dummy1.in_elevator);
		printf("FAIL: ADDING to NULL,      GOT: %d %d %d %d %d \n.", head->arrival_floor, head->arrival_time, head->dest_floor, head->id, head->in_elevator);
		fprintf(f, "FAIL: ADDING to NULL, EXPECTED: %d %d %d %d %d \n.", dummy1.arrival_floor, dummy1.arrival_time, dummy1.dest_floor, dummy1.id, dummy1.in_elevator);
		fprintf(f, "FAIL: ADDING to NULL,      GOT: %d %d %d %d %d \n.", head->arrival_floor, head->arrival_time, head->dest_floor, head->id, head->in_elevator);
	}

	//adding at second position
	returned_ptr = add_request_queue(head, dummy2);
	if (returned_ptr == head)
	{
		printf("PASS: Addind to 2nd, returning ptr is == to old head.\n");
		fprintf(f, "PASS: Addind to 2nd, returning ptr is == to old head.\n");
	}
	else
	{
		printf("FAIL: Addind to 2nd, returning ptr is != to head.\n");
		printf("FAIL: Addind to 2nd, returning ptr = %p head = %p.\n", returned_ptr, head);
		fprintf(f, "FAIL: Addind to 2nd, returning ptr is != to head.\n");
		fprintf(f, "FAIL: Addind to 2nd, returning ptr = %p head = %p.\n", returned_ptr, head);
	}
	head = returned_ptr;
	cur = head;
	if (compare(dummy1, *head))
	{
		printf("PASS: ADDING to 2nd, 1st position unchanged.\n");
		fprintf(f, "PASS: ADDING to 2nd, 1st position unchanged.\n");
	}
	else
	{
		printf("FAIL: ADDING to 2nd, 1st position EXPECTED: %d %d %d %d %d \n.", dummy1.arrival_floor, dummy1.arrival_time, dummy1.dest_floor, dummy1.id, dummy1.in_elevator);
		printf("FAIL: ADDING to 2nd, 1st position      GOT: %d %d %d %d %d \n.", head->arrival_floor, head->arrival_time, head->dest_floor, head->id, head->in_elevator);
		fprintf(f, "FAIL: ADDING to 2nd, 1st position EXPECTED: %d %d %d %d %d \n.", dummy1.arrival_floor, dummy1.arrival_time, dummy1.dest_floor, dummy1.id, dummy1.in_elevator);
		fprintf(f, "FAIL: ADDING to 2nd, 1st position      GOT: %d %d %d %d %d \n.", head->arrival_floor, head->arrival_time, head->dest_floor, head->id, head->in_elevator);
	}
	cur = cur->next;
	if (compare(dummy2, *cur))
	{
		printf("PASS: ADDING to 2nd, 2nd position succesfully added.\n");
		fprintf(f, "PASS: ADDING to 2nd, 2nd position succesfully added.\n");
	}
	else
	{
		printf("FAIL: ADDING to 2nd, 2nd position EXPECTED: %d %d %d %d %d \n.", dummy2.arrival_floor, dummy2.arrival_time, dummy2.dest_floor, dummy2.id, dummy2.in_elevator);
		printf("FAIL: ADDING to 2nd, 2nd position      GOT: %d %d %d %d %d \n.", head->arrival_floor, head->arrival_time, head->dest_floor, head->id, head->in_elevator);
		fprintf(f, "FAIL: ADDING to 2nd, 2nd position EXPECTED: %d %d %d %d %d \n.", dummy2.arrival_floor, dummy2.arrival_time, dummy2.dest_floor, dummy2.id, dummy2.in_elevator);
		fprintf(f, "FAIL: ADDING to 2nd, 2nd position      GOT: %d %d %d %d %d \n.", head->arrival_floor, head->arrival_time, head->dest_floor, head->id, head->in_elevator);
	}

	//add to third position
	returned_ptr = add_request_queue(head, dummy3);
	if (returned_ptr == head)
	{
		printf("PASS: Addind to 3rd, returning ptr is == to old head.\n");
		fprintf(f, "PASS: Addind to 3rd, returning ptr is == to old head.\n");
	}
	else
	{
		printf("FAIL: Addind to 3rd, returning ptr is != to head.\n");
		printf("FAIL: Addind to 3rd, returning ptr = %p head = %p.\n", returned_ptr, head);
		fprintf(f, "FAIL: Addind to 3rd, returning ptr is != to head.\n");
		fprintf(f, "FAIL: Addind to 3rd, returning ptr = %p head = %p.\n", returned_ptr, head);
	}
	head = returned_ptr;
	cur = head;
	if (compare(dummy1, *head))
	{
		printf("PASS: ADDING to 3rd, 1st position unchanged.\n");
		fprintf(f, "PASS: ADDING to 3rd, 1st position unchanged.\n");
	}
	else
	{
		printf("FAIL: ADDING to 3rd, 1st position  EXPECTED: %d %d %d %d %d \n.", dummy1.arrival_floor, dummy1.arrival_time, dummy1.dest_floor, dummy1.id, dummy1.in_elevator);
		printf("FAIL: ADDING to 3rd, 1st position       GOT: %d %d %d %d %d \n.", head->arrival_floor, head->arrival_time, head->dest_floor, head->id, head->in_elevator);
		fprintf(f, "FAIL: ADDING to 3rd, 1st position  EXPECTED: %d %d %d %d %d \n.", dummy1.arrival_floor, dummy1.arrival_time, dummy1.dest_floor, dummy1.id, dummy1.in_elevator);
		fprintf(f, "FAIL: ADDING to 3rd, 1st position       GOT: %d %d %d %d %d \n.", head->arrival_floor, head->arrival_time, head->dest_floor, head->id, head->in_elevator);
	}
	cur = cur->next;
	if (compare(dummy2, *cur))
	{
		printf("PASS: ADDING to 3rd, 2nd position succesfully added.\n");
		fprintf(f, "PASS: ADDING to 3rd, 2nd position succesfully added.\n");
	}
	else
	{
		printf("FAIL: ADDING to 3rd, 2nd position EXPECTED: %d %d %d %d %d \n.", dummy2.arrival_floor, dummy2.arrival_time, dummy2.dest_floor, dummy2.id, dummy2.in_elevator);
		printf("FAIL: ADDING to 3rd, 2nd position      GOT: %d %d %d %d %d \n.", cur->arrival_floor, cur->arrival_time, cur->dest_floor, cur->id, cur->in_elevator);
		fprintf(f, "FAIL: ADDING to 3rd, 2nd position EXPECTED: %d %d %d %d %d \n.", dummy2.arrival_floor, dummy2.arrival_time, dummy2.dest_floor, dummy2.id, dummy2.in_elevator);
		fprintf(f, "FAIL: ADDING to 3rd, 2nd position      GOT: %d %d %d %d %d \n.", cur->arrival_floor, cur->arrival_time, cur->dest_floor, cur->id, cur->in_elevator);
	}
	cur = cur->next;
	if (compare(dummy3, *cur))
	{
		printf("PASS: ADDING to 3rd, 3rd position succesfully added.\n");
		fprintf(f, "PASS: ADDING to 3rd, 3rd position succesfully added.\n");
	}
	else
	{
		printf("FAIL: ADDING to 3rd, 3rd position EXPECTED: %d %d %d %d %d \n.", dummy3.arrival_floor, dummy3.arrival_time, dummy3.dest_floor, dummy3.id, dummy3.in_elevator);
		printf("FAIL: ADDING to 3rd, 3rd position      GOT: %d %d %d %d %d \n.", cur->arrival_floor, cur->arrival_time, cur->dest_floor, cur->id, cur->in_elevator);
		fprintf(f, "FAIL: ADDING to 3rd, 3rd position EXPECTED: %d %d %d %d %d \n.", dummy3.arrival_floor, dummy3.arrival_time, dummy3.dest_floor, dummy3.id, dummy3.in_elevator);
		fprintf(f, "FAIL: ADDING to 3rd, 3rd position      GOT: %d %d %d %d %d \n.", cur->arrival_floor, cur->arrival_time, cur->dest_floor, cur->id, cur->in_elevator);
	}
	fflush(f);
	fclose(f);
	return;
}

struct passenger create_dummy_passenger(int val)
{
	struct passenger dummy;
	dummy.arrival_floor = val;
	dummy.arrival_time = val;
	dummy.dest_floor = val;
	dummy.id = val;
	dummy.in_elevator = 1;
	dummy.next = NULL;
	return dummy;
}

bool compare(struct passenger a, struct passenger b)
{

	int count = 0;
	count += a.arrival_floor == b.arrival_floor;
	count += a.arrival_time == b.arrival_time;
	count += a.id == b.id;
	count += a.dest_floor == b.dest_floor;
	count += a.in_elevator == b.in_elevator;
	return count == 5;
}
