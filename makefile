

CC=gcc
INCLUDE= -Iinclude/ 
CFLAGS=-Wall -Wno-unused-result -Wno-unknown-pragmas -Wfatal-errors -fPIC $(INCLUDE)

SRC = src/globals.c src/add_passenger_floor.c src/add_request_queue.c src/count_passenger.c src/create_elevator_array.c src/create_floor_array.c\
 src/remove_passenger_floor.c src/input_floors.c src/input_lifts.c src/moving_lift_down.c src/passengers_drop.c src/passengers_take_in.c src/read_passenger.c\
 src/remove_passenger_queue.c src/is_lift_on_floor.c src/moving_lift_up.c src/travel_log_file.c src/max_waiting_time.c src/average_waiting_time.c

main: src/main.c $(SRC)
	$(CC) $(CFLAGS) $? -o $@

debug: src/main.c $(SRC)
	$(CC) -g $(CFLAGS) $? -o $@


tests: test/test_cli_update.c
	$(CC) $(CFLAGS) $? -o $@
