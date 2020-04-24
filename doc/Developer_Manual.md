# Introduction

Elevator simulation is a software to simulate the operations of multiple elevators in a commercial building, by creating an algorithm.

# Requirement

Software simulates Elevator scheduling in a building for an day by reading the input file with Paaseger ID,timestamp,start and destination floor. The text file must be stored in data/input.txt.

# Assumption

- User gives the number of floors and elevators in the building, the value should be less than or equal to 100. In dynamic case this is reduced to 10 to make all elevators fit the screen.
- The elevators are assumed to be at the same location in the building.
- At the start of the simulation all the elevators are assumed to be on the 1st floor.
- The weight of each passenger is assumed to be constant. This allows the simulator to establish weight limits as the number of passengers in the elevator. In this program it is set to 10.
- A fixed time has been assumed for lifts to move from x floor to x+1 and x-1 floors.Each elevator takes 3 seconds to go from one floor to another floor.
- The time that the elevator stops on a floor depends on that number of passengers getting in or out. It is assumed that it takes 2 sec for a passenger to get in or out. So the stop time of an elevator at a floor will be 2n, where n is the number of passengers getting in or out of the lift.
- The elevators are assumed to have a single entry point for both exit and entry.

# Program Flow

The program flow for the application is as follows:

- The main.c file calls the functions for static_simulation and in release 2 dynamc_simulation based on user input to run the alogorithm.
- The static_simulation/dynamc_simulation function calls:
  - The function in input_lifts.c to get number of lifts from the user.
  - The function in input_floors.c to get number of floors from the user.
  - The function in create_elevator_array.c to create array for every elevator.
  - The function in create_floor_array.c to create array for every floor to hold waiting passeger.
  - The function in count_passenger.c to count the number of passenger in the input file.
  - The function in read_passenger.c to store the passenger details to passenger structure.
  - The function in add_request_queue.c to add passenger requests to a queue.
  - The function in is_lift_on_floor.c to check the lift status. If it is moving or not.
  - The function in passengers_drop.c to drop the passenger at the floor returning number of passengers dropped.
  - The function in passengers_take_in.c to take the passenger on floor based on maiximum count and space in elevator.
  - The function in add_passenger_floor.c to add passenger to the floor array.
  - The function in remove_passenger_queue.c to remove the passenger from request queue.
  - The function in moving_lift_down.c to change lift direction to down.
  - The function in moving_lift_up.c to change the lift direction to up.
  - The function in average_waiting_time.c to calculate the average and waiting time.
  - The function in max_waiting_time.c to calculate maximum waiting time.
  - The function in is_lift_empty.c to check the space in elevator
  - The function in remove_passenger_floor.c to remove the passenger from the floor array.
    The dynamc_simulation also calls these functions:
  - The function in input_static_dynamic.c to get whether user want static or dynamic simulation.
  - The function in read_user_input_validate.c to read and validate the inputs from user console for a passenger.
  - The function in emergency_stop_handling.c to to bring the lifts to nearest floor incase of emergency.
  - The function in cli_update.c to display elevator information on screen.
  - The function in input_after_stop.c to get input from user when emergency situation encountered.
  - The function in travel_log_file.c is used to write the two output files to the data folder travel_log.txt and waiting_times.txt.

- The program implements the SCAN algorithm. The elevators move in one direction until all requests along it path are completed or it reaches the end (top or ground floor). At which point it changes direction and waits for new requests before moving again in required direction. 
  - Down in case of at top floor.
  - Up in case of ground floor.
  - Any direction in all other cases.
- All the elevators start at ground floor with direction of travel set to up.
- The passenger array stores the data from input file. This data is then added to passenger_queue when the time of arrival of the passenger = the time of the simulation. This is done at very start of the main while loop in static_simulation and  dynamic simulation function.
- This is followed by checking if passenger need to get on of off the elevator at the floor the elevator is currently at.
- The passenger_queue is then traversed to check if any passengers in the queue can have their requests processed. Those passed are removed from queue and added to the proper entry in floor_array. Which is an array of passenger pointers.
- The elevator timer is then checked and decremened if it greater than 0. If it is equal to 0. We check if passengers need to get off or do we need to change the floor of the elevator. In case of changing floor +3 seconds are added to the elevator timer.
- The program continues until the iterator reaches predifined values. After which the average and max time are written to the files and the program exits.
# Documentation

Complete documentation of the source code can be found [here](/index.html).
