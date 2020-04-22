
CC=gcc
INCLUDE= -I./include/ 
TESTINCLUDE = -I./test/include/
CFLAGS=-Wall -Wno-unused-result -Wno-unknown-pragmas -Wfatal-errors -fPIC $(INCLUDE)
TESTCFLAGS=-Wall -Wno-unused-result -Wno-unknown-pragmas -Wfatal-errors -fPIC $(TESTINCLUDE) $(INCLUDE)

SRC = src/globals.c src/add_passenger_floor.c src/add_request_queue.c src/count_passenger.c src/create_elevator_array.c src/create_floor_array.c\
 src/remove_passenger_floor.c src/input_floors.c src/input_lifts.c src/moving_lift_down.c src/passengers_drop.c src/passengers_take_in.c src/read_passenger.c\
 src/remove_passenger_queue.c src/is_lift_empty.c src/is_lift_on_floor.c src/moving_lift_up.c src/travel_log_file.c src/max_waiting_time.c src/average_waiting_time.c\
 src/static_simulation.c src/dynamic_simulation.c

TEST = test/test_cases.c test/test_add_request_queue.c test/test_average_waiting_time.c test/test_count_passenger.c test/test_create_elevator_array.c test/test_create_floor_array.c test/test_input_after_stop.c\
 test/test_input_lifts.c test/test_is_lift_empty.c test/test_is_lift_on_floor.c test/test_max_waiting_time.c test/test_moving_lift_down.c test/test_passenger_take_in.c\
 test/test_remove_passenger_queue.c test/test_read_passenger.c 


all: elevator tests

elevator: src/main.c $(SRC)
	$(CC) $(CFLAGS) $? -o $@

debug: src/main.c $(SRC)
	$(CC) -g $(CFLAGS) $? -o $@

tests: test/test_main.c $(SRC) $(TEST)
	$(CC) $(TESTCFLAGS) $? -o $@
