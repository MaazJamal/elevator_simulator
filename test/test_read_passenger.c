
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structures.h"

/**
On account of erraneous data in input file,the program exits.
So test cases are executed by means of switch cases.
Read passeneger function is included in the prgram here and function call involves 2 parameters.
(i.e) structure array and input file,Inorder to test for various erraneous conditions of input file.

**/
static void read_passenger(struct passenger p[], char *f)
{

	int i = 0;
	int count = 0;
	int fd = fileno(f); //fileno function returns the mode of file.
	if (fd == -1)
	{
		printf("Error - input file\n");
		exit(1); //program ends incase of absence of file in specified path.
	}
	if (f == NULL)
	{
		printf("Error -opening the file\n");
		exit(1); //program ends incase of error in opening the  input file.
	}

	if (NULL != f)
	{
		int size;
		fseek(f, 0, SEEK_END);
		size = ftell(f);

		if (0 == size)
		{
			printf("Input file is empty\n");
			exit(1);
		}
	}
	rewind(f);

	char c[100];
	while (fscanf(f, "%s", c) != EOF)
	{

		//	printf("%s",c,);

		if (count == 0)
		{

			p[i].id = atoi(c);
			count++;
			if ((p[i].id == 0) || (p[i].id < 1))
			{
				printf("p[%d] -Passenger ID column contains invalid data in  file (i.e)%d\n", i, p[i].id);
				exit(1); //program ends incase of erraneous data.
			}
		}

		else if (count == 1)
		{

			p[i].arrival_time = atoi(c);
			count++;
			if ((p[i].arrival_time == 0) || (p[i].arrival_time > 86400) || (p[i].arrival_time < 1))
			{
				printf("p[%d].-arrival_time column contains invalid data in file (i.e)%d\n", i, p[i].arrival_time);
				exit(1); //program ends incase of erraneous data.
			}
		}
		else if (count == 2)
		{

			p[i].arrival_floor = atoi(c);
			count++;
			if ((p[i].arrival_floor == 0) || (p[i].arrival_floor > 100) || (p[i].arrival_floor < 1))
			{
				printf("p[%d].arrival_floor column contains invalid data  in file (i.e)%d\n", i, p[i].arrival_floor);
				exit(1); //program ends incase of erraneous data.
			}
		}
		else if (count == 3)
		{
			//printf("\n%s\n",c);
			p[i].dest_floor = atoi(c);
			count = 0;
			if ((p[i].dest_floor == 0) || (p[i].dest_floor > 100) || (p[i].dest_floor < 1))
			{
				printf("p[%d].dest_floor column contains invalid data in  file (i.e)%d\n", i, p[i].dest_floor);
				exit(1); //program ends incase of erraneous data.
			}
			i++;
		}
	}

	printf("read_passenger is executed-Size of array of structure passenger is %d \n", i);
	fclose(f);
	printf("Input file is closed-read_passenger function\n");
}
void test_read_passenger(void)
{

	int testcase;
	printf("Choose between the tests.\n\n");
	printf("1.File not available in specified path.Expected Output-User Notification and Program Exists. \n\n\n");
	printf("2.File available in specified path is empty.Expected Output-User Notification and Program Exists.\n\n\n");
	printf("3.File contains invalid data in passenger ID column.Expected Output-User Notification and Program Exists.\n\n\n");
	printf("4.File contains invalid data in arrival time column.Expected Output-User Notification and Program Exists. \n\n\n");
	printf("5.File contains invalid data in arrival floor column.Expected Output-User Notification and Program Exists. \n\n\n");
	printf("6.File contains invalid data in destination floor column .Expected Output-User Notification and Program Exists.\n\n\n");
	printf("7.File containing valid data;array of structure passenger could be accessed \n");
	printf("Expected output-User notification on Close of file and number of elements in array\n\n\n\n");
	printf("Enter the test case number to be verified------");
	scanf("%d", &testcase);
	printf("\nEntered test case number is %d\n", testcase);
	printf("Take look at results file-results_read_passenger, for user notifications.\n");
	printf("Please remember to close the results file .");
	switch (testcase)
	{
	//File not available in specified path
	case 1:
	{
		FILE *fp, *f;
		f = fopen("test/data/rad_passr_testcase1.txt", "r");
		fp = freopen("test/results/results_read_passenger.txt", "w+", stdout);
		struct passenger pas[100];
		read_passenger(pas, f);
		//printf("PASS;Input:Invalid input file;Expected Output:Error - input file\n");
		fflush(fp);
		fclose(fp);
		break;
	}
		//File available in specified path is empty
	case 2:
	{
		FILE *fp, *f;
		f = fopen("test/data/read_passenger_test_case2.txt", "r");
		fp = freopen("test/results/results_read_passenger.txt", "w+", stdout);
		struct passenger pas[100];
		read_passenger(pas, f);
		//printf("PASS;Input:Input file available is empty;Expected Output:Error - Input file is empty\n");
		fflush(fp);
		fclose(fp);
		break;
	}
	//File contains invalid data in passenger ID column
	case 3:
	{
		FILE *fp, *f;
		f = fopen("test/data/read_passenger_test_case3.txt", "r");
		fp = freopen("test/results/results_read_passenger.txt", "w+", stdout);
		struct passenger pas[100];
		read_passenger(pas, f);
		//printf("PASS;Input:Invalid data in Passenger ID column ;Expected Output:Passenger ID column contains invalid data  in file\n");
		fflush(fp);
		fclose(fp);
		break;
	}
	//File contains invalid data in arrival time column
	case 4:
	{
		FILE *fp, *f;
		f = fopen("test/data/read_passenger_test_case4.txt", "r");
		fp = freopen("test/results/results_read_passenger.txt", "w+", stdout);
		struct passenger pas[100];
		read_passenger(pas, f);
		//printf("PASS;Input:Invalid data in arrival time column ;Expected Output:arrival time column contains invalid data in  file\n");
		fflush(fp);
		fclose(fp);
		break;
	}
	//File contains invalid data in arrival floor column
	case 5:
	{
		FILE *fp, *f;
		f = fopen("test/data/read_passenger_test_case5.txt", "r");
		fp = freopen("test/results/results_read_passenger.txt", "w+", stdout);
		struct passenger pas[100];
		read_passenger(pas, f);
		printf("PASS;Input:Invalid data in arrival floor column ;Expected Output:arrival floor column contains invalid data in  file\n");
		fflush(fp);
		fclose(fp);
		break;
	}
	//File contains invalid data in destination floor column
	case 6:
	{
		FILE *fp, *f;
		f = fopen("test/data/read_passenger_test_case6.txt", "r");
		fp = freopen("test/results/results_read_passenger.txt", "w+", stdout);
		struct passenger pas[100];
		read_passenger(pas, f);
		printf("PASS;Input:Invalid data in destination floor column ;Expected Output:destination floor column contains invalid data in  file\n");
		fflush(fp);
		fclose(fp);
		break;
	}
	//File containing valid data;array of structure passenger could be accessed
	case 7:
	{
		FILE *fp, *f;
		f = fopen("test/data/read_passenger_test_case7.txt", "r");
		fp = freopen("test/results/results_read_passenger.txt", "w+", stdout);
		struct passenger pas[100];
		read_passenger(pas, f);
		printf("\n pas[2].arrival time=%d, is printed from 3rd  row to check if the array of structure passenger can be accessed\n\n", pas[2].arrival_time);
		printf("PASS;Input:Valid input file;array of structure passenger could be accessed .\n");
		fflush(fp);
		fclose(fp);
		break;
	}

	default:
	{
		FILE *fp;
		fp = freopen("test/results/results_read_passenger.txt", "w+", stdout);
		printf("Enter a valid test case number.");
		break;
	}

		//return(0);
	}
}
