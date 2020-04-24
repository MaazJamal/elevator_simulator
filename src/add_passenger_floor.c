/** @file add_passenger_floor.c
 * 
 * @brief Contains the definition for add_passenger_floor file.
 * */

#include "add_passenger_floor.h"
#include "structures.h"
#include "globals.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/** @brief Adds a passenger to the floor.
 * 
 * @detail takes a floor array. The index of floor and passenger info. It then allocates a memory location and add
 *  the passenger to the passenger queue on that floor.
 * @param[in, out] floor an array of pointer of type struct passenger, Used to form passenger queue on each floor.
 * @param[in] index the index at to add the passenger.
 * @param[in] passenger_info struct passenger that contains the information about the passenger.
 * 
 * @return void does not return anythin 
 * */

void add_passenger_floor(struct passenger *floor[], int index, struct passenger passenger_info)
{

	assert(index >= 0);
	assert(index < floor_count);
	static int no_of_passengers_added = 0;
	struct passenger *cur;
	cur = floor[index];
	if (cur == NULL)
	{
		struct passenger *temp = (struct passenger *)malloc(sizeof(struct passenger));
		*temp = passenger_info;
		floor[index] = temp;
		floor[index]->next = NULL;
		printf("passenger %d arrived at floor: %d. No of passengers Added: %d\n", temp->id, index + 1, ++no_of_passengers_added);
		return;
	}
	while (cur->next != NULL)
	{
		cur = cur->next;
	}

	struct passenger *temp = (struct passenger *)malloc(sizeof(struct passenger));
	*temp = passenger_info;
	cur->next = temp;
	temp->next = NULL;
	printf("passenger %d arrived at floor: %d. No of passengers Added: %d\n", temp->id, index + 1, ++no_of_passengers_added);
	return;
}