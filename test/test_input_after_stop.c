/**
 * @file test_input_after_stop.c
 *
 * @brief When the simulation encounters a emergency stop situation input_after_stop function is invoked prompting for the user input.
 *
 *
 * @author Hariprasad Munusamy  - HariprasadMunusamy@cmail.carleton.ca
 * @return int Returns the user input (1 - to continue the simulation, 0 - to end the simulation)
 */
#include <stdio.h>
#include <stdlib.h>

static int input_after_stop();

void test_input_after_stop(void)
{
	FILE *test_results = fopen("test/results/results_input_after_stop.txt", "w");
	int t = input_after_stop();
	if (t == 0 || t == 1)
	{
		char temp[200];
		sprintf(temp, "PASS: Valid Input and returned successfully, Expected Output: 1 or 0, Output:1 or 0 \n");
		printf(temp);
		fprintf(test_results, temp);
	}
}

static int input_after_stop()
{
	int st; //Stores the user status
	printf("Enter\n");
	printf("1 - To continue simulation\n");
	printf("0 - To end simulation\n");
	scanf("%d", &st);
	if (st == 0)
	{
		return 0; // return 0 to end the simulation
	}
	else if (st == 1)
	{
		return 1; //return 1 to continue simulation
	}
	else
	{
		printf("Invalid input\n");
		input_after_stop();
	}
}