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
	freopen("test/data/test_input_after_stop.txt", "r", stdin);
    int arr[4];
    arr[0] = input_after_stop();
    arr[1] = input_after_stop();
    arr[2] = input_after_stop();
    arr[3] = input_after_stop();
	//int t = input_after_stop();
	if (arr[0]==0)
	{
		char temp[200];
		sprintf(temp, "PASS: Valid Input and returned successfully, Expected Output: 0, Output:0\n");
		printf(temp);
		fprintf(test_results, temp);
	}
	else
	{
		char temp[200];
		sprintf(temp, "Fail: Valid Input and returned invlaid, Expected Output: 0\n");
		printf(temp);
		fprintf(test_results, temp);
	}
	if (arr[1]==1)
	{
		char temp[200];
		sprintf(temp, "PASS: Valid Input and returned successfully, Expected Output: 1, Output:0\n");
		printf(temp);
		fprintf(test_results, temp);
	}
	else
	{
		char temp[200];
		sprintf(temp, "Fail: Valid Input and returned invlaid, Expected Output: 1\n");
		printf(temp);
		fprintf(test_results, temp);
	}
	if (arr[2]>1)
	{
		char temp[200];
		sprintf(temp, "PASS: Invalid Input other tha 1/0 and returned successfully\n");
		printf(temp);
		fprintf(test_results, temp);
	}
	else
	{
		char temp[200];
		sprintf(temp, "Fail: InValid Input and returned invlaid\n");
		printf(temp);
		fprintf(test_results, temp);
	}
	if (arr[3]==-1)
	{
		char temp[200];
		sprintf(temp, "PASS: Character Input and returned successfully, Expected Output: -1, Output:-1\n");
		printf(temp);
		fprintf(test_results, temp);
	}
	else
	{
		char temp[200];
		sprintf(temp, "Fail: Character Input and returned invlaid, Expected Output: -1\n");
		printf(temp);
		fprintf(test_results, temp);
	}
    fflush(test_results);
    fclose(test_results);
}

static int input_after_stop()
{
	int st,chk; //Stores the user status
 	//printf("Enter\n");
	//printf("1 - To continue simulation\n");
    //printf("0 - To end simulation\n");
    //scanf("%d",&st);
    while ((chk = scanf("%d", &st)) == 0)  
    {
        // clear what is left, the * means only match and discard:
        scanf("%*[^\n]");
        // input was not a number, ask again:
        //printf("Invalid entry, enter a number: ");
        return -1;
    }
    if(st==0)
    {
    	return st; // return 0 to end the simulation
	}
	else if(st==1)
	{
		return st;  //return 1 to continue simulation
	}
	else
	{
		//printf("Invalid input\n");
		return st;
	}
}
