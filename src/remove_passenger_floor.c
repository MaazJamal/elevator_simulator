
#include "remove_passenger_floor.h"

#include <stdlib.h>
#include "globals.h"
#include <assert.h>



int remove_passenger_floor(struct passenger* floor[], int cur_floor){

	assert(cur_floor >0);
	assert(cur_floor<floor_count);

	// if( (*floor)[cur_floor].next == NULL){ // incase there is no next node.
	// 	(*floor)[cur_floor].arrival_floor = 0;
	// 	(*floor)[cur_floor].arrival_floor = 0;
	// 	(*floor)[cur_floor].dest_floor = 0;
	// 	(*floor)[cur_floor].id = 0;
	// 	(*floor)[cur_floor].in_elevator = 0;
	// }
	// else{ // free the head and assign new head.
	// }
	
	struct passenger* temp;
	temp = floor[cur_floor];
	floor[cur_floor] = floor[cur_floor]->next;
	free(temp);
	return 1;
}