#include "functions.h"
#include "test_functions.h"
#include <stdio.h>

void test_cases()
{
	int test_choice; //stores user input for testing
	printf("Enter ur choice\n");
	printf("1.To test count_passenger\n");
	printf("2.To test read_passenger\n");
	printf("3.To test input_floors\n");
	printf("4.To test add_request_queue\n");
	printf("5.To test input_lifts\n");
	printf("6.To test moving_lift_down\n");
	printf("7.To test passenger_take_in\n");
	printf("8.To test remove_passenger_queue\n");
	scanf("%d", &test_choice);
	//switch to execute
	switch (test_choice)
	{
	case 1:
		//test_count_passenger();
		printf("Executed count_passenger test results log can be found in test/results \n");
		break;
	case 2:
		test_read_passenger();
		printf("Executed read_passenger test results log can be found in test/results \n");
		break;
	case 3:
		test_input_floors();
		printf("Executed input_floors test results log can be found in test/results \n");
		break;
	case 4:
		test_add_request_queue();
		printf("Executed add_request_queue test results log can be found in test/results \n");
		break;
	case 5:
		test_input_lifts();
		printf("Executed input_lifts test results log can be found in test/results \n");
		break;
	case 6:
		test_moving_lift_down();
		printf("Executed moving_lift_down test results log can be found in test/results \n");
		break;
	case 7:
		test_passenger_take_in();
		printf("Executed passenger_take_in test results log can be found in test/results \n");
		break;
	case 8:
		test_remove_passenger_queue();
		printf("Executed remove_passenger_queue test results log can be found in test/results \n");
		break;
	default:
		printf("Invalid option. Run program again.\n");
	}
}
