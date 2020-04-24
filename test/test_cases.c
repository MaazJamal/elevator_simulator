/** @file test_cases.c
 * 
 *  @brief Contains all the tests and menue logic to choose each test. 
 * 
 *  */


#include "functions.h"
#include "test_functions.h"
#include <stdio.h>

#if __unix__ || __CYGWIN__
#include <unistd.h>
#elif _WIN32
#include <io.h>
#endif

void test_cases(void)
{
	int exit_choice = 0; //stores user input for testing
	while (exit_choice == 0)
	{
		int test_choice = 0;
		int stdin_descriptor = dup(0);
		int stdout_descriptor = dup(1);
		puts("Please note due to nature of some of the tests the program may need to  be run again.");
		puts("Some tests are supposed to cause the program to exit.\n");
		puts("Enter a negative number to exit.");
		printf("Enter ur choice\n");
		puts("1. To run test for add_request_queue().");
		puts("2. To run tests for average_waiting_time().");
		puts("3. To run tests for count_passenger().");
		puts("4. To run tests for create_elevator_array().");
		puts("5. To run tests for create_floor_array().");
		puts("6. To run tests for input_after_stop().");
		puts("7. To run tests for input_floors().");
		puts("8. To run tests for input_lifts().");
		puts("9. To run tests for is_lift_empty().");
		puts("10. To run tests for is_lift_on_floor().");
		puts("11. To run tests for max_waiting_time().");
		puts("12. To run tests for moving_lift_down().");
		puts("13. To run tests for passenger_take_in().");
		puts("14. To run tests for read_passenger().");
		puts("15. To run tests for remove_passenger_queue().");
		puts("16. To run tests for cli_update().");
		puts("17. To run tests for add_passenger_floor().");
		puts("18. To run tests for remove_passenger_floor().");
				
		int read = 0;
		while (read == 0)
		{
			read = scanf("%d", &test_choice);
			if (read == 0)
			{
				puts("Incorrect input");
				scanf("%*[^\n]");
				puts("Enter your choice");
			}
			else if (test_choice < 0)
			{
				puts("Exiting");
				exit_choice = 1;
				continue;
			}
		}
		//switch to execute
		if (test_choice >= 0)
		{
			switch (test_choice)
			{
			case 1:
				test_add_request_queue();
				puts("Tests for add_request_queue() Done. Results may be found in test/results.");

				break;
			case 2:
				test_average_waiting_time();
				puts("Tests for average_waiting_time() Done. Results may be found in test/results.");
				break;
			case 3:
				test_count_passenger();
				puts("Tests for count_passenger() Done. Results may be found in test/results.");
				break;
			case 4:
				test_create_elevator_array();
				puts("Tests for create_elevator_array() Done. Results may be found in test/results.");
				break;
			case 5:
				test_create_floor_array();
				puts("Tests for create_floor_array() Done. Results may be found in test/results.");
				break;
			case 6:
				test_input_after_stop();
				puts("Tests for input_after_stop() Done. Results may be found in test/results.");
				break;
			case 7:
				test_input_floors();
				puts("Tests for test_input_floors() Done. Results may be found in test/results.");
				break;
			case 8:
				test_input_lifts();
				puts("Tests for input_lifts() Done. Results may be found in test/results.");
				break;
			case 9:
				test_is_lift_empty();
				puts("Tests for is_lift_empty() Done. Results may be found in test/results.");
				break;
			case 10:
				test_is_lift_on_floor();
				puts("Tests for is_lift_on_floor Done. Results may be found in test/results.");
				break;
			case 11:
				test_max_waiting_time();
				puts("Tests for max_waiting_time Done. Results may be found in test/results.");
				break;
			case 12:
				test_moving_lift_down();
				puts("Tests for moving_lift_down() Done. Results may be found in test/results.");
				break;
			case 13:
				test_passenger_take_in();
				puts("Tests for passenger_take_in() Done. Results may be found in test/results.");
				break;
			case 14:
				test_read_passenger();
				puts("Tests for test_read_passenger() Done. Results may be found in test/results.");
				break;
			case 15:
				test_remove_passenger_queue();
				puts("Tests for remove_passenger_queue() Done. Results may be found in test/results.");
				break;
			case 16:
				test_cli_update();
				puts("Tests for cli_update() Done.");
				break;
			case 17:
				test_add_passenger_floor();
				puts("Tests for add_passenger_floor() Done.");
				break;
			case 18:
				test_remove_passenger_floor();
				puts("Tests for remove_passenger_floor() Done.");
				break;
			default:
				printf("Invalid option.\n");
				break;
			}
		}
		dup2(stdin_descriptor, 0);
		dup2(stdout_descriptor, 1);
	}
}
