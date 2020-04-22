# Elevator_Simulator

Elevator_Simulator is a software that simulates Elevators in a commercial building.

# Authors

- Hariprasad Munusamy - Carleton University
- Maaz Jamal - Carleton University
- Ritika Arora - Carleton University
- Divyalakshmi Padmanaban - Ottawa University

# Installation

Installation steps are mentioned in [INSTALL.md](INSTALL.md)

# Usage

To run, you must first compile the repository. Follow the instructions in [INSTALL.md](INSTALL.md).Then you can follow instructions mentioned in
[User_Manual.md](doc/User_Manual.md).

# File Structure

The correct file structure

```
├── INSTALL.md 	-> Installation Guide
├── LICENSE 	-> License file
├── Makefile 	-> Makefile
├── README.md 	-> Readme file
├── bin 	-> Binary directory
├── doc
│   └── html 	-> Doxygen document
├── include 	-> Header files
│   ├── input_static_dynamic.h
│   ├── input_floors.h
│   ├── input_lifts.h
│   ├── count_passenger.h
│   ├── read_passenger.h
│   ├── moving_lift_up.h
│   ├── moving_lift_down.h
│   ├── input_after_stop.h
│   ├── is_lift_empty.h
│   ├── is_lift_on_floor.h
│   ├── passengers_take_in.h
│   ├── passengers_drop.h
│   ├── read_user_input_validate.h
│   ├── create_elevator_array.h
│   ├── add_request_queue.h
│   ├── add_passenger_floor.h
│   ├── create_floor_array.h
│   ├── add_passenger_floor.h
│   ├── remove_passenger_floor.h
│   ├── remove_passenger_queue.h
│   ├── emergency_stop _handling.h
│   ├── average_maximum waiting_time.h
│   ├── travel_log_file.h
│   ├── cli_update.h
│   ├── static_simulation.h
│   ├── dynamic_simulation.h
│   ├── simulations.h
│   └── structures.h
├── obj 	-> Object files
├── src 	-> Source files for elevator_simulator
│   ├── input_static_dynamic.c
│   ├── input_floors.c
│   ├── input_lifts.c
│   ├── count_passenger.c
│   ├── read_passenger.c
│   ├── moving_lift_up.c
│   ├── moving_lift_down.c
│   ├── input_after_stop.c
│   ├── is_lift_empty.c
│   ├── is_lift_on_floor.c
│   ├── passengers_take_in.c
│   ├── passengers_drop.c
│   ├── read_user_input_validate.c
│   ├── create_elevator_array.c
│   ├── add_request_queue.c
│   ├── add_passenger_floor.c
│   ├── create_floor_array.c
│   ├── add_passenger_floor.c
│   ├── remove_passenger_floor.c
│   ├── remove_passenger_queue.c
│   ├── emergency_stop _handling.c
│   ├── average_maximum waiting_time.c
│   ├── travel_log_file.c
│   ├── static_simulation.c
│   ├── dynamic_simulation.c
│   ├── max_waiting_time.c
│   ├── main.c
│   ├── globals.c
│   └── cli_update.c
└── test
    ├── test_main.c	-> Main function for testing
    ├── test_cases.c
    ├── test_remove_passenger_queue.c
    ├── test_read_passenger.c
    ├── test_passenger_take_in.c
    ├── test_max_waiting_time.c
    ├── test_is_lift_on_floor.c
    ├── test_lift_empty.c
    ├── test_input_floors.c
    ├── test_input_after_stop.c
    ├── test_create_floor_array.c
    ├── test_count_passenger.c
    ├── test_add_request_queue.c
    ├── test_average_waiting_time.c
    ├── test_input_lifts.c
    ├── test_moving_lift_down.c
    ├── include
    │   └── test_functions.h
    ├── data -> Contains text file inputs for user tests
    └── results -> Contains the txt file logs of the results.

```

# For Developers

The developer manual is available [here](doc/Developer_Manual.md).

# License

This project is licensed under the GPL 2.0 License - see the LICENSE.md file for details

# Acknowledgements

Thank to Dr. Cristina Ruiz Martin for providing guidance on how to develop the software.
