# Introduction

Elevator simulation is a software to simulate the operations of multiple elevators in a commercial building, by creating an algorithm.

# Requirement

Software simulates Elevator scheduling in a building for an day by reading the input file with Paaseger ID,timestamp,start and destination floor.

# Assumption

- User gives the number of floors and elevators in the building, the value should be less than 100.
- The elevators are assumed to be at the same location in the building.
- At the start of the simulation all the elevators are assumed to be on the 1st floor.
- The weight of each passenger is assumed to be constant. This allows the simulator to establish weight limits as the number of passengers in the elevator.
- A fixed time has been assumed for lifts to move from x floor to x+1 and x-1 floors.Each elevator takes 3 seconds to go from one floor to another floor.
- The time that the elevator stops on a floor depends on that number of passengers getting in or out. It is assumed that it takes 2 sec for a passenger to get in or out. So the stop time of an elevator at a floor will be 2n, where n is the number of passengers getting in or out of the lift.
- The elevators are assumed to have a single for both exit and entry.


# Program Flow

The program flow for the application is as follows:


- The main.c file calls the functions in static_simulation or dynamc_simulation based on user input to run the alogorithm.
- The static_simulation/dynamc_simulation function calls:
  - The function in input_lifts.c to get number of lifts from the user.
  - The function in input_floors.c to get number of floors from the user.
  - The function in create_elevator_array.c to create array for every elevator.
  - The function in create_floor_array.c to create array for every floor to hold waiting passeger.
  - The function in count_passenger.c to count the number of passenger in the input file.
  - The function in read_passenger.c to store the passenger details to passenger structure.
  - The function in add_request_queue.c to add passenger requests to a queue.
  - The function in is_lift_on_floor.c to check the lift status moving or not.
  - The function in passengers_drop.c to drop the passenger at the floor with time buffer.
  - The function in passenger_takein.c to take the passenger based on maximum count.
  - The function in add_passenger_floor.c to add passenger to the floor array.
  - The function in remove_passenger_queue.c to remove the passenger from request queue.
  - The function in moving_lift_down.c to move the lift down.
  - The function in moving_lift_up.cc to move the lift up.
  - The function in average_maximum_waiting_time.c to calculate the average and maximum waiting time.
  - The function in max_waiting_time.c to calculate the average and maximum waiting time.
  - The function in is_lift_empty.c to check the space in elevator
  - The function in remove_passenger_floor.c to remove the passenger from the floor array.
  - The function in travel_log_file.c to remove the passenger from the floor array.
The dynamc_simulation function calls:
  - The function in input_static_dynamic.c to get version input from user.
  - The function in read_user_input_validate.c to validate the inputs from user console.
  - The function in emergency_stop _handling.c to to bring the lifts to 1st floor incase of emergency
  - The function in cli_update.c to display elevator information on screen.
  - The function in input_after_stop.c to get input from user when emergency situation encountered. 

# Documentation

Complete documentation of the source code can be found [here](https://github.com/MaazJamal/elevator_simulator/tree/devel/doc/html/index.html).
