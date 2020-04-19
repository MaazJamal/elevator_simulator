#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int static_simulation(void);
int dynamc_simulation(void);

int main()
{
	static_simulation();
	return 0;
}

int static_simulation(void)
{

	elevator_count = -1;
	while (elevator_count == -1)
	{
		elevator_count = input_lifts();
	}
	floor_count = -1;

	while (floor_count == -1)
	{
		floor_count = input_floors();
	}

	struct elevator *elevator_arr = create_elevator_array(elevator_count);
	struct passenger **floor_array = create_floor_array(floor_count);
	passenger_count = count_passenger();
	struct passenger *passenger_array = (struct passenger *)calloc(passenger_count, sizeof(struct passenger));
	read_passenger(passenger_array);
	unsigned int t = 0;
	struct passenger *passenger_queue = NULL;

	int prev_time_index = 0;

	while (t < 5000) //864000 for whole day
	{

		// Add passenger with current time step to queue

		for (int i = prev_time_index; i < passenger_count; i++)
		{

			//Assume the passenger_array is sorted by arrival time.
			//prev_time_index prevents us from starting at previous index
			if (passenger_array[i].arrival_time == t)
			{
				printf("Adding to request queue From file. %d\n",t);
				passenger_queue = add_request_queue(passenger_queue, passenger_array[i]);
				prev_time_index++;
			}
			else
			{
				break;
			}
		}

		for (int i = 0; i < elevator_count; i++)
		{

			if (is_lift_on_floor(elevator_arr, i))
			{
				int drop_delay = 0;
				int add_delay = 0;
				if (elevator_arr[i].passenger_count >0)
				{
				//remove any passengers that need to get off
				drop_delay = passengers_drop(elevator_arr,i,floor_array,elevator_arr[i].cur_floor);
				printf("Dropping Passengers, Delay:%d time:%d\n",drop_delay,t);
				}
				if (elevator_arr[i].passenger_count < elevator_arr[i].max_passenger)
				{
					add_delay = passengers_take_in(elevator_arr,i,floor_array,elevator_arr[i].cur_floor);
					printf("Adding Passengers, Delay%d: time:%d\n",add_delay,t);
				}
				int total_delay = 2*drop_delay+2*add_delay;
				elevator_arr[i].timer += total_delay;
			}

			struct passenger *cur = passenger_queue;
			int index = 0;
			while (cur != NULL)
			{ //iterating over passenger queue

				bool direction_up = (cur->arrival_floor < cur->dest_floor);
				bool direction_down = (cur->arrival_floor > cur->dest_floor);
				if (elevator_arr[i].direction_up == direction_up || elevator_arr[i].direction_down == direction_down)
				{
					struct passenger temp = *cur;
					temp.next = NULL; // removing this from passenger queue list
					printf("Add Passenger Floor Up=Up or Down=Down: t%d\n",t);
					add_passenger_floor(floor_array, index, temp);
					passenger_queue = remove_passenger_queue(index, passenger_queue);
					printf("Add Remove Passenger queue Up=Up or Down=Down: t%d\n",t);
				}

				else
				{

					//is elevator at top floor
					if (elevator_arr[i].cur_floor == floor_count)
					{
						//change direction to move down
						int success = moving_lift_down(elevator_arr, i);
						if (success == -1)
						{
							fprintf(stderr, "Could not change direction of elevator to Down. \n");
						}
						struct passenger temp = *cur;
						temp.next = NULL; // removing this from passenger queue list
						printf("Add Passenger Floor change to Down: t%d\n",t);
						add_passenger_floor(floor_array, index, temp);
						passenger_queue = remove_passenger_queue(index, passenger_queue);
						printf("Add Remove Passenger change to Down=Down: t%d\n",t);
						
					}

					//is elevator at ground floor. Can cause issues at start.
					else if (elevator_arr[i].cur_floor == 1)
					{
						//change direction to move up
						moving_lift_up(elevator_arr, i);
						struct passenger temp = *cur;
						temp.next = NULL; // removing this from passenger queue list
						printf("Add passenger floor change to up: t%d\n",t);
						add_passenger_floor(floor_array, index, temp);
						passenger_queue = remove_passenger_queue(index, passenger_queue);
						printf("Add Remove Passenger change to up: t%d\n",t);
						
					}

					
					else
					{
						// bool to check if elevator and passenger inside are travelling in same direction
						bool passenger_elevator_dir = false;
						for (int j = 0; j < elevator_arr[i].passenger_count; i++)
						{
							if (elevator_arr[i].passenger_arr[j].in_elevator)
							{
								bool up = elevator_arr[i].passenger_arr[j].dest_floor > elevator_arr[i].passenger_arr[j].arrival_floor;
								if (elevator_arr[i].direction_up == up || elevator_arr[i].direction_down != up)
								{
									passenger_elevator_dir = true;
									break;
								}
							}
						}

						//if no passengers are travelling in direction of lift change lift direction
						if (!passenger_elevator_dir)
						{
							if (elevator_arr[i].direction_up)
							{
								moving_lift_down(elevator_arr, i);
							}
							else if (elevator_arr[i].direction_down)
							{
								moving_lift_up(elevator_arr, i);
							}

							struct passenger temp = *cur;
							temp.next = NULL; // removing this from passenger queue list
							printf("Add passenger floor No pass in lift direction. t%d\n",t);
							add_passenger_floor(floor_array, index, temp);
							passenger_queue = remove_passenger_queue(index, passenger_queue);
							printf("Remove passenger queue No pass in lift direction. t%d\n",t);
							
						}
					}
				}

				//potential bug here due to deleting nodes in remove_passenger_queue
				
				cur = passenger_queue; //bug fix start
				if (cur != NULL) //incase we deleted only node queue
				{ 
					for(int q_index = 0; q_index <index;q_index++)
					{
						cur = cur->next; //iterate until we reach the spot of deletion
					} 
				} //bug fix end
				index++;

			} //End of while loop iterating over queue

			
		} //end of elevator loop

		// output_data_metric();
		t++;
	}
	return 1;
}