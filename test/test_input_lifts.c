/** @file test_input_lifts.c
 * @brief This file contains function test_input_lifts() that provides unit testing for function input_lifts().
 * @author Maaz Jamal
 * */

#include <stdio.h>
#include "input_lifts.h"

void test_input_lifts(void)
{
    FILE *test_results = fopen("test/results/results_inputs_lifts.txt", "w");
    freopen("test/data/maaz_test_inputs.txt", "r", stdin);
    int arr[13];
    arr[0] = input_lifts();
    arr[1] = input_lifts();
    arr[2] = input_lifts();
    arr[3] = input_lifts();
    arr[4] = input_lifts();
    arr[5] = input_lifts();
    arr[6] = input_lifts();
    arr[7] = input_lifts();
    arr[8] = input_lifts();
    arr[9] = input_lifts();
    arr[10] = input_lifts();
    arr[11] = input_lifts();
    arr[12] = input_lifts();
    int case_id = 0;
    //Test case 1 input abd
    if (arr[0] == -1)
    {
        char temp[100];
        sprintf(temp, "PASS: Input: abd, Expected Output: -1, Output: %d .\n",
                arr[0]);
        printf(temp);
        fprintf(test_results, temp);
    }

    else
    {
        char temp[100];
        sprintf(temp, "FAIL: Input: abd, Expected Output: -1, Output: %d .\n",
                arr[0]);
        printf(temp);
        fprintf(test_results, temp);
    }

    //Test case 2 input wbb120
    if (arr[1] == -1)
    {
        char temp[100];
        sprintf(temp, "PASS: Input: wbb120, Expected Output: -1, Output: %d .\n",
                arr[1]);
        printf(temp);
        fprintf(test_results, temp);
    }
    else
    {
        char temp[100];
        sprintf(temp, "FAIL: Input: wbb120, Expected Output: -1, Output: %d .\n",
                arr[1]);
        printf(temp);
        fprintf(test_results, temp);
    }

    //Test case 3 input 0
    if (arr[2] == -1)
    {
        char temp[100];
        sprintf(temp, "PASS: Input: 0, Expected Output: -1, Output: %d .\n",
                arr[2]);
        printf(temp);
        fprintf(test_results, temp);
    }
    else
    {
        char temp[100];
        sprintf(temp, "FAIL: Input: 0, Expected Output: -1, Output: %d .\n",
                arr[2]);
        printf(temp);
        fprintf(test_results, temp);
    }

    //Test case 4 input -100
    if (arr[3] == -1)
    {
        char temp[100];
        sprintf(temp, "PASS: Input: -100, Expected Output: -1, Output: %d .\n",
                arr[3]);
        printf(temp);
        fprintf(test_results, temp);
    }
    else
    {
        char temp[100];
        sprintf(temp, "FAIL: Input: -100, Expected Output: -1, Output: %d .\n",
                arr[3]);
        printf(temp);
        fprintf(test_results, temp);
    }

    //Test case 5 input 101
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

    //Test case 6 input 1
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

    //Test case 7 input 100
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