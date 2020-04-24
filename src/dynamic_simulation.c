/** @file dynamic_simulation.c
 * 
 * @brief This file contains the definition of dynamic_simulation
 * The function contains the algorithm for dynamic release of the program
 *  
 * @author Maaz Jamal
 * */

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dynamic_functions.h"
#include <time.h>

/** @brief This function contains the working logic of the elevator array function for dynamic release.
 * 
 * @detail Contains the logic for the dynamic version. It contains the main logic loop for travel of
 * elevators .The loop for placing passengers on floors and the complete flow of the program.
 * Plus additional functional calls for the dynamic release.
 * 
 * @return return 1 for successful completion.
 * */

int dynamic_simulation(void)
{

	elevator_count = -1;
	while (elevator_count == -1)
	{
		elevator_count = input_lifts(1);
	}
	floor_count = -1;

	while (floor_count == -1)
	{
		floor_count = input_floors();
	}
	bool *stop_at_floor_global = (bool *)calloc(floor_count, sizeof(bool)); //! A boolean array that shows if elevator needs to stop at a floor. to pick a passenger.
	struct elevator *elevator_arr = create_elevator_array(elevator_count);	//! Array conatining Elevators
	struct passenger **floor_array = create_floor_array(floor_count);		//! Array to pointer of type passenger. Stores passengers on floors.
	passenger_count = count_passenger();
	struct passenger *passenger_array = (struct passenger *)calloc(passenger_count, sizeof(struct passenger)); //! stores the passengers from input file.
	read_passenger(passenger_array);
	unsigned int t = 0;						  //! main time counter
	struct passenger *passenger_queue = NULL; //! A queue of request made by passengers

	int prev_time_index = 0;

	bool enable_realtime = true;   // Realtime or full-speed;
	bool enable_user_input = true; // ask user for input or not;
	bool exit_main_loop = false;   // should we exit main loop if user orders simulation stop
	time_t start_time;
	time_t end_time;
	int time_difference = 0;
	while (t < 1000) //86400 for whole day
	{

		if (t % 50 == 0 && enable_user_input)
		{														  //choices
			struct passenger temp_passenger = {0, 0, 0, 0, 0, 0}; //To store the user entered passenger
			int stop_input = 0;
			bool incorrect_choice = true;
			while (incorrect_choice)
			{
				puts("CHOSE AMONG THE FOLLOWING CHOICES:");
				puts("1- Enter A Passenger Details.");
				puts("2- Create an Emergency stop.");
				puts("3- Enable/Disable realtime timer.");
				puts("4- Do not ask for input again & Disable realtime timer.");
				puts("5- Exit the simulation.");
				int user_choice = 0;
				while (scanf("%d", &user_choice) == 0)
				{
					puts("Incorrect Choice Please Try Again.");
					scanf("%*[\n]"); //discard all inputs until newline character
				}
				if (user_choice > 0 && user_choice < 6)
				{
					incorrect_choice = false; //made correct choice no exit selection loop.
					switch (user_choice)
					{

					//1- Enter A Passenger Details.
					case 1:
						read_user_input_validate(&temp_passenger, &t);
						passenger_queue = add_request_queue(passenger_queue, temp_passenger);
						break;
					//2- Create an Emergency stop.
					case 2:
						emergency_stop_handling(elevator_arr, t);
						while ((stop_input = input_after_stop() != -1))
						{ //loop until we get right input
						};
						if (stop_input == 0)
						{
							exit_main_loop = true;
						}
						break;
					case 3:
						enable_realtime = !enable_realtime; //toggle
						printf("Set Real-time to : %d\n", enable_realtime);
						break;
					case 4:
						enable_realtime = false;
						enable_user_input = false;
						break;
					case 5:
						exit_main_loop = true;
						break;
					}
				}
			}
			if(exit_main_loop){ //exit main loop;
				break;
			}
		}
		//set start time
		start_time = time(NULL);
		//update the cli
		cli_update(elevator_arr, t);

		// Add passenger with current time step to queue
		for (int i_pass = prev_time_index; i_pass < passenger_count; i_pass++) //debugged works perfectly
		{

			//Assume the passenger_array is sorted by arrival time.
			//prev_time_index prevents us from starting at previous index
			if (passenger_array[i_pass].arrival_time == t)
			{

				passenger_queue = add_request_queue(passenger_queue, passenger_array[i_pass]);
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
				int stop_change = elevator_arr[i].cur_floor - 1;
				if (elevator_arr[i].passenger_count > 0)
				{
					if (elevator_arr[i].stop_at_floor[stop_change])
					{ //remove any passengers that need to get off
						drop_delay = passengers_drop(elevator_arr, i, elevator_arr[i].cur_floor, t);

						if (drop_delay > 0 || elevator_arr[i].passenger_count >= elevator_arr[i].max_passenger) //dropped passengers here or lift full
						{
							elevator_arr[i].stop_at_floor[stop_change] = false; //dropped passengers here
						}
					}
				}
				if (elevator_arr[i].passenger_count < elevator_arr[i].max_passenger)
				{

					add_delay = passengers_take_in(elevator_arr, i, floor_array, elevator_arr[i].cur_floor, t);
					elevator_arr[i].stop_at_floor[stop_change] = false;
					if (floor_array[stop_change] == NULL)
					{
						stop_at_floor_global[stop_change] = false;
					}
					else
					{ //happens in case the lift gets full and their are still passengers on floor.
						stop_at_floor_global[stop_change] = true;
					}
					elevator_arr[i].stop_at_floor[stop_change] = false; //lift has taken in or dropped passengers or is full and has completed it purpose on floor so we set to false.
				}
				int total_delay = 2 * drop_delay + 2 * add_delay;
				elevator_arr[i].timer += total_delay;
			}

			struct passenger *cur = passenger_queue;
			int index = 0;
			while (cur != NULL)
			{ //iterating over passenger queue

				bool direction_up = (cur->arrival_floor <= cur->dest_floor); //passenger direction up
				bool direction_down = (cur->arrival_floor >= cur->dest_floor);
				if (elevator_arr[i].direction_up == direction_up || elevator_arr[i].direction_down == direction_down)
				{
					bool is_above = cur->arrival_floor >= elevator_arr[i].cur_floor;
					bool is_below = cur->arrival_floor <= elevator_arr[i].cur_floor;
					if (elevator_arr[i].direction_up == is_above || elevator_arr[i].direction_down == is_below)
					{ //elevator can pick this person up
						struct passenger temp = *cur;
						temp.next = NULL;								  // removing this from passenger queue list
						int arrival_floor_index = temp.arrival_floor - 1; //-1 because of mismatch between array and input file

						add_passenger_floor(floor_array, arrival_floor_index, temp);
						stop_at_floor_global[temp.arrival_floor - 1] = true;
						passenger_queue = remove_passenger_queue(index, passenger_queue);
						index--; //list is smaller by one node.
					}
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

						int arrival_floor_index = temp.arrival_floor - 1;
						add_passenger_floor(floor_array, arrival_floor_index, temp);
						stop_at_floor_global[temp.arrival_floor - 1] = true;
						passenger_queue = remove_passenger_queue(index, passenger_queue);
						index--; //list is smaller by one node.
					}

					//is elevator at ground floor. Can cause issues at start.
					else if (elevator_arr[i].cur_floor == 1)
					{
						//change direction to move up
						moving_lift_up(elevator_arr, i);
						struct passenger temp = *cur;
						temp.next = NULL; // removing this from passenger queue list

						int arrival_floor_index = temp.arrival_floor - 1;
						add_passenger_floor(floor_array, arrival_floor_index, temp);
						stop_at_floor_global[temp.arrival_floor - 1] = true;
						passenger_queue = remove_passenger_queue(index, passenger_queue);
						index--; //list is smaller by one node.
					}

					else //passenger in lift go in opposite direction of the lift
					{
						// bool to check if elevator and passenger inside are travelling in same direction
						bool passenger_elevator_dir = false;
						for (int j = 0; j < elevator_arr[i].passenger_count; j++)
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

							int arrival_floor_index = temp.arrival_floor - 1;
							add_passenger_floor(floor_array, arrival_floor_index, temp);
							stop_at_floor_global[temp.arrival_floor - 1] = true;
							passenger_queue = remove_passenger_queue(index, passenger_queue);
							index--; //list is smaller by one node.
						}
					}
				}

				//potential bug here due to deleting nodes in remove_passenger_queue

				cur = passenger_queue; //bug fix start
				if (cur != NULL)	   //incase we deleted only node queue
				{
					for (int q_index = 0; q_index < index + 1; q_index++)
					{
						cur = cur->next; //iterate until we reach the spot of deletion
					}
				} //bug fix end
				index++;

			} //End of while loop iterating over queue

			//move elevator here
			if (elevator_arr[i].passenger_count > 0) //if there are passengers then lift needs to move
			{
				elevator_arr[i].moving = true;
				elevator_arr[i].between_floor = true;
			}
			else
			{
				elevator_arr[i].moving = false; //elevator is stopped and empty now
				if (elevator_arr[i].timer != 0)
				{
					elevator_arr[i].between_floor = true; //time for passenger to drop out.
				}
				else
				{
					elevator_arr[i].between_floor = false; //elevator is stationary at current floor and can be used again.
					if (elevator_arr[i].cur_floor == 1)
					{ //elevator at ground floor can only move up.
						moving_lift_up(elevator_arr, i);
					}
					else if (elevator_arr[i].cur_floor == floor_count) //At top floor and can only move down
					{
						moving_lift_down(elevator_arr, i);
					}
					else
					{ //elevator in middle can go anywhere
						elevator_arr[i].direction_up = true;
						elevator_arr[i].direction_down = true;
					}
				}
			}

			if (elevator_arr[i].timer > 0)
			{
				elevator_arr[i].timer--;
			}
			if (elevator_arr[i].timer == 0)
			{ //we may need to move to another floor
				int current_floor = elevator_arr[i].cur_floor;
				bool passengers_above = false; //are there passengers above for drop or pickup?
				bool passengers_below = false; //are there passengers below for drop or pickup?
				if (elevator_arr[i].direction_up)
				{
					for (int k = current_floor; k < floor_count; k++) //start at current floor and search up
					{												  //k = current floor becuse searching up and array numbering starts from 0 so curent_floor as index is 1 floor above
						//if we are below a floor and need to stop on it to drop a passenger.
						bool condition_a = elevator_arr[i].stop_at_floor[k];
						// if we are below a floor and neee to stop on it to pick a passenger.
						bool condition_b = stop_at_floor_global[k];
						if (condition_a || condition_b)
						{
							passengers_above = true;
							elevator_arr[i].stop_at_floor[k] = true;
							stop_at_floor_global[k] = false; //lift assigned to this floor
							break;
						}
					}
				}
				else if (elevator_arr[i].direction_down)
				{
					for (int k = current_floor - 2; k >= 0; k--)
					{ //current_floor-2 because of array numbering and file numbering mismatch
						//if we are above a floor and need to stop on it to drop passengers.
						bool condition_a = elevator_arr[i].stop_at_floor[k];
						//if we are above a floor and need to stop on it to pick a passenger.
						bool condition_b = stop_at_floor_global[k];
						if (condition_a || condition_b)
						{
							passengers_below = true;
							elevator_arr[i].stop_at_floor[k] = true;
							stop_at_floor_global[k] = false; //lift assigned to this floor

							break;
						}
					}
				}

				if (passengers_above)
				{
					current_floor++;
				}
				else if (passengers_below)
				{
					current_floor--;
				}
				elevator_arr[i].cur_floor = current_floor; //changed the floor
				if (elevator_arr[i].stop_at_floor[current_floor - 1] || stop_at_floor_global[current_floor - 1])
				{ //do we need to stop at this floor
					elevator_arr[i].moving = false;
					elevator_arr[i].between_floor = false;
					elevator_arr[i].stop_at_floor[current_floor - 1] = true; //setting to true so that the lift stops at this floor
																			 //stop_at_floor_global[current_floor - 1] = false;
				}
				else if (passengers_above || passengers_below) //we do not need to stop at this floor.
				{
					elevator_arr[i].moving = true;
					elevator_arr[i].between_floor = true;
					elevator_arr[i].timer += 3; //add 3 sec till next floor
				}
				else
				{
					elevator_arr[i].moving = false;
					elevator_arr[i].between_floor = false;
				}

				if (elevator_arr[i].direction_up && !passengers_above)
				{ //if no passengers above then lift should change direction to down.
					if (current_floor != 1 && elevator_arr[i].passenger_count > 0)
					{
						moving_lift_down(elevator_arr, i);
					}
				}
				else if (elevator_arr[i].direction_down && !passengers_below)
				{
					if (current_floor != floor_count && elevator_arr[i].passenger_count > 0)
					{
						moving_lift_up(elevator_arr, i);
					}
				}
			}

		} //end of elevator loop

		end_time = time(NULL);
		time_difference = 0;
		while (time_difference < 1 && enable_realtime)
		{ //wait one second
			end_time = time(NULL);
			time_difference = end_time - start_time;
		}
		t++;
	}
	struct passenger dummy;			 //placeholder to pass to log. it should not be used.
	travel_log_file(dummy, 0, 0, 3); //choose mode to write max,avg time to file.
	return 1;
}