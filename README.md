# Elevator_Simulator

Elevator_Simulator is a software that simulates Elevator in a commercial building.


# Authors

- Hariprasad Munusamy - HariprasadMunusamy@cmail.carleton.ca (101132017) - Carleton University
- Maaz Jamal  - maazjamal@cmail.carleton.ca (101127351) - Carleton University
- Ritika Arora - ritikaarora@cmail.carleton.ca (101141126) - Carleton University
- Divyalakshmi Padmanaban  - Dpadm049@uottawa.ca (300110144) - Carleton University

# Installation

Installation steps are mentioned in [INSTALL.md](https://github.com/MaazJamal/elevator_simulator/blob/devel/INSTALL.md)

# Usage

To run, you must first install it. Then you can follow instructions mentioned in
[User_Manual.md](https://github.com/MaazJamal/elevator_simulator/blob/devel/doc/User_Manual.md).

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
│   ├── travel_.h
│   └── cli_update.h
├── install.sh 	-> Installation script
├── obj 	-> Object files
├── elevator_simulator_config 	-> Doxygen Configuration files
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
│   ├── max_waiting_time.c
│   ├── travel_log_file.c
│   └── cli_update.c
└── test
    ├── test_cases.c	-> Main function for testing
    ├── test_add_request_queue.c
    ├── test_average_waiting_time.c
    ├── test_count_passenger.c 
    ├── test_create_elevator_array.c
    ├── test_create_floor_array.c
    ├── test_input_after_stop.c
    ├── test_input_floors.c
    ├── test_input_lifts.c
    ├── test_is_lift_empty.c
    ├── test_is_lift_on_floor.c
    ├── test_max_waiting_time.c
    ├── test_moving_lift_down.c 
    ├── test_passenger_take_in.c
    ├── test_read_passenger.c
    |── test_remove_passenger_queue.c
  
```

# For Developers

The developer manual is available [here](https://github.com/MaazJamal/elevator_simulator/blob/devel/doc/Developer_Manual.md).

# License

This project is licensed under the GPL 2.0 License - see the LICENSE.md file for details

# Acknowledgements

Thank to Dr. Cristina Ruiz Martin for providing guidance on how to develop the software.
