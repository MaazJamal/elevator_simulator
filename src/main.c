#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int static_simulation(void);
int dynamc_simulation(void);

int main(){
	static_simulation();
	return 0;
}

static_simulation(void){
	
	elevator_count = -1;
	while(elevator_count != -1){
	elevator_count = input_lifts();
	}
	floor_count = -1;

	while(floor_count != -1){
		floor_count = input_floors();
	}
	
	struct elevator* elevator_arr = create_elevator_array(elevator_count);
	struct passenger* floor_array = create_floor_array(floor_count);
	passenger_count = count_passenger();
	struct passenger* passenger_array; 
	passenger_array = read_passnger();
	unsigned int t = 0;
	struct passenger* passenger_queue = NULL;
	
	int prev_time_index = 0;

	while ( t < 86400 ){

		// Add passenger with current time step to queue
		
		for(int i = prev_time_index; i < passenger_count; i++){
			
			//Assume the passenger_array is sorted by arrival time.
			//prev_time_index prevents us from starting at previous index
			if (passenger_array[i].arrival_time == t){
				add_request_queue(passenger_queue, passenger_array[i]);
				prev_time_index++;
			}
			else{
				break;
			}
		}


		for(int i = 0; i< elevator_count; i++){

			if( is_lift_on_floor(elevator_arr,i)){
				
				//remove any passengers that need to get off
				passengers_drop(&elevator_arr[i]);
				
				while(elevator_arr[i].passenger_count < elevator_arr[i].max_passenger){
					passenger_takein(&elevator_arr[i]);
				}

			}

			struct passenger* cur = passenger_queue;
			int index = 0;
			while(cur != NULL){
			
			bool direction_up = (cur->arrival_floor < cur->dest_floor);
			bool direction_down =  (cur->arrival_floor > cur->dest_floor);
			if (elevator_arr[i].direction_up == direction_up || elevator_arr[i].direction_up == direction_down){
				add_passenger_floor(index, passenger_queue);
				remove_passenger_queue(index, passenger_queue);
			}

			else{
				
				//is elevator at top floor
				if(elevator_arr[i].cur_floor == floor_count){
					//change direction to move down
					int success = moving_lift_down(elevator_arr, i);
					if( success == -1){
						fprintf(stderr,"Could not change direction of elevator to Down. \n");
					}
					add_passenger_floor(index, passenger_queue);
					remove_passenger_queue(index, passenger_queue);
				}

				//is elevator at ground floor. Can cause issues at start.
				else if(elevator_arr[i].cur_floor == 1){
					//change direction to move up
					moving_lift_up(elevator_arr, i);
					add_passenger_floor(index, passenger_queue);
					remove_passenger_queue(index, passenger_queue);
				}

				// bool to check if elevator and passenger inside are travelling in same direction
				else{
					bool passenger_elevator_dir = false;
					for(int j = 0; j<elevator_arr[i].passenger_count; i++){
						if( elevator_arr[i].passenger_arr[j].in_elevator){
							bool up = elevator_arr[i].passenger_arr[j].dest_floor > elevator_arr[i].passenger_arr[j].arrival_floor;
							if(elevator_arr[i].direction_up == up || elevator_arr[i].direction_down != up){
								passenger_elevator_dir = true;
								break;
							} 
						}
					}

					//if no passengers are travelling in direction of lift change lift direction
					if ( !passenger_elevator_dir){
						if( elevator_arr[i].direction_up){
							moving_lift_down(elevator_arr,i);
						}
						else if(elevator_arr[i].direction_down){
							moving_lift_up(elevator_arr,i);
						}
						
						add_passenger_floor(index, passenger_queue);
						remove_passenger_queue(index, passenger_queue);
					}
				}
			}

			//potential bug here due to deleting nodes in remove_passenger_queue
			cur = cur->next;
			index++;
		
		} //End of elevator loop

		t++;

	}

	output_data_metric();
	return;
}
