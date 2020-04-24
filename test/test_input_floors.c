/** @file test_input_floors.c
 * 
 * @brief contains the test cases for testing the input_floors() function.
 * 
 * */


#include <stdio.h>
#include "input_floors.h"
#include "test_functions.h"

/**

Calls the function input_floors.c with input from input_input_floors.txt.
Prints the PASS /FAIL status ,by accessing the  return from input_floors function.
results_input_floors file contains the results.

**/

void test_input_floors(void)
{
    FILE *test_results;
    test_results = fopen("test/results/results_input_floors.txt", "w");
    freopen("test/data/input_input_floors.txt", "r", stdin);
    int arr[13];
    arr[0] = input_floors();
    arr[1] = input_floors();
    arr[2] = input_floors();
    arr[3] = input_floors();
    arr[4] = input_floors();
    arr[5] = input_floors();
    arr[6] = input_floors();
    arr[7] = input_floors();
    arr[8] = input_floors();
    arr[9] = input_floors();
    arr[10] = input_floors();
    arr[11] = input_floors();
    arr[12] = input_floors();
    arr[13] = input_floors();

    int case_id = 0;
    //Test case 1 -input abcd

    if (arr[0] == -1)
    {
        char temp[100];
        sprintf(temp, "PASS: Input: abcd, Expected Output: -1, Output: %d .\n",
                arr[0]);
        printf(temp);
        fprintf(test_results, temp);
    }

    else
    {
        char temp[100];
        sprintf(temp, "FAIL: Input: abcd, Expected Output: -1, Output: %d .\n",
                arr[0]);
        printf(temp);
        fprintf(test_results, temp);
    }
    //Test case 2- input abcd123
    if (arr[1] == -1)
    {
        char temp[100];
        sprintf(temp, "PASS: Input: abcd123, Expected Output: -1, Output: %d .\n",
                arr[0]);
        printf(temp);
        fprintf(test_results, temp);
    }

    else
    {
        char temp[100];
        sprintf(temp, "FAIL: Input: abcd123, Expected Output: -1, Output: %d .\n",
                arr[0]);
        printf(temp);
        fprintf(test_results, temp);
    }
    //Test case 3- input 0
    if (arr[2] == -1)
    {
        char temp[100];
        sprintf(temp, "PASS: Input: 0, Expected Output: -1, Output: %d .\n",
                arr[0]);
        printf(temp);
        fprintf(test_results, temp);
    }

    else
    {
        char temp[100];
        sprintf(temp, "FAIL: Input: 0, Expected Output: -1, Output: %d .\n",
                arr[0]);
        printf(temp);
        fprintf(test_results, temp);
    }
    //Test case 4- input -100
    if (arr[2] == -1)
    {
        char temp[100];
        sprintf(temp, "PASS: Input: -100, Expected Output: -1, Output: %d .\n",
                arr[0]);
        printf(temp);
        fprintf(test_results, temp);
    }

    else
    {
        char temp[100];
        sprintf(temp, "FAIL: Input: -100, Expected Output: -1, Output: %d .\n",
                arr[0]);
        printf(temp);
        fprintf(test_results, temp);
    }

    //Test case 5 -input 101
    if (arr[4] == -1)
    {
        char temp[100];
        sprintf(temp, "PASS: Input: 101, Expected Output: -1, Output: %d .\n",
                arr[4]);
        printf(temp);
        fprintf(test_results, temp);
    }
    else
    {
        char temp[100];
        sprintf(temp, "FAIL: Input: 101, Expected Output: -1, Output: %d .\n",
                arr[4]);
        printf(temp);
        fprintf(test_results, temp);
    }

    //Test case 6 -input 1
    if (arr[5] == 1)
    {
        char temp[100];
        sprintf(temp, "PASS: Input: 1, Expected Output: 1, Output: %d .\n",
                arr[5]);
        printf(temp);
        fprintf(test_results, temp);
    }
    else
    {
        char temp[100];
        sprintf(temp, "FAIL: Input: 1, Expected Output: 1, Output: %d .\n",
                arr[5]);
        printf(temp);
        fprintf(test_results, temp);
    }

    //Test case 7 -input 100
    case_id = 6;
    if (arr[case_id] == 100)
    {
        char temp[100];
        sprintf(temp, "PASS: Input: 100, Expected Output: 100, Output: %d .\n",
                arr[case_id]);
        printf(temp);
        fprintf(test_results, temp);
    }
    else
    {
        char temp[100];
        sprintf(temp, "FAIL: Input: 100, Expected Output: 100, Output: %d .\n",
                arr[case_id]);
        printf(temp);
        fprintf(test_results, temp);
    }

    //Test case 8 input 50
    case_id = 7;
    if (arr[case_id] == 50)
    {
        char temp[100];
        sprintf(temp, "PASS: Input: 50, Expected Output: 50, Output: %d .\n",
                arr[case_id]);
        printf(temp);
        fprintf(test_results, temp);
    }
    else
    {
        char temp[100];
        sprintf(temp, "FAIL: Input: 50, Expected Output: 50, Output: %d .\n",
                arr[case_id]);
        printf(temp);
        fprintf(test_results, temp);
    }

    //Test case 9 input 23.3
    case_id = 8;
    if (arr[case_id] == 23)
    {
        char temp[100];
        sprintf(temp, "PASS: Input: 23.3, Expected Output: 23, Output: %d .\n",
                arr[case_id]);
        printf(temp);
        fprintf(test_results, temp);
    }
    else
    {
        char temp[100];
        sprintf(temp, "FAIL: Input: 23.3, Expected Output: 23, Output: %d .\n",
                arr[case_id]);
        printf(temp);
        fprintf(test_results, temp);
    }

    //Test case 10 input 0.9
    case_id = 9;
    if (arr[case_id] == -1)
    {
        char temp[100];
        sprintf(temp, "PASS: Input: 0.9, Expected Output: -1, Output: %d .\n",
                arr[case_id]);
        printf(temp);
        fprintf(test_results, temp);
    }
    else
    {
        char temp[100];
        sprintf(temp, "FAIL: Input: 0.9, Expected Output: -1, Output: %d .\n",
                arr[case_id]);
        printf(temp);
        fprintf(test_results, temp);
    }

    //Test case 11 input 1.0
    case_id = 10;
    if (arr[case_id] == 1)
    {
        char temp[100];
        sprintf(temp, "PASS: Input: 1.0, Expected Output: 1, Output: %d .\n",
                arr[case_id]);
        printf(temp);
        fprintf(test_results, temp);
    }
    else
    {
        char temp[100];
        sprintf(temp, "FAIL: Input: 1.0, Expected Output: 1, Output: %d .\n",
                arr[case_id]);
        printf(temp);
        fprintf(test_results, temp);
    }

    //Test case 12 input 100.1
    case_id = 11;
    if (arr[case_id] == 100)
    {
        char temp[100];
        sprintf(temp, "PASS: Input: 100.1, Expected Output: 100, Output: %d .\n",
                arr[case_id]);
        printf(temp);
        fprintf(test_results, temp);
    }
    else
    {
        char temp[100];
        sprintf(temp, "FAIL: Input: 100.1, Expected Output: 100, Output: %d .\n",
                arr[case_id]);
        printf(temp);
        fprintf(test_results, temp);
    }

    //Test case 13 input 100.0
    case_id = 12;
    if (arr[case_id] == 100)
    {
        char temp[100];
        sprintf(temp, "PASS: Input: 100.0, Expected Output: 100, Output: %d .\n",
                arr[case_id]);
        printf(temp);
        fprintf(test_results, temp);
    }
    else
    {
        char temp[100];
        sprintf(temp, "FAIL: Input: 100.0, Expected Output: 100, Output: %d .\n",
                arr[case_id]);
        printf(temp);
        fprintf(test_results, temp);
    }
    fflush(test_results);
    fclose(test_results);
}
