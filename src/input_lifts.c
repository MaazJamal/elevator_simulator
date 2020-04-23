/**
 * @file input_lifts.c
 * @brief contains the definition of input_lifts
 * 
 * @author Maaz Jamal
 * 
 * */

#include <stdio.h>
#include "input_lifts.h"

/**
 * @brief Prompt the user to enter the number of lifts and takes the input
 * 
 * The function prompts the user to enter the number of lifts. If the lift count
 * is less than one or greater than 100 (mode 0) or 10 (mode 1)the function displays an error message 
 * and returns -1. 
 * If the user enters anything other than a numeric entry. The function displays
 * and error message, discards all inputs in stdin stream and returns -1.
 * If the user enters numeric value. It accepts the only Whole number part of the entry 
 * and returns the entered whole number value.
 * 
 * @param[in] mode integer to select mode. mode 0 for 100 max, 1 for 10 max numbers.
 * 
 * @return int Returns -1 if errors in input and integer if input is fine. 
 *  */

int input_lifts(int mode)
{
    int temp;
    puts("Please Enter an integer number for the number of Elevator in building.");
    int bounds = 0;
    if (mode == 0)
    {
        puts("Valid entries are 1-100");
        bounds = 100;
    }
    if (mode == 1)
    {
        puts("Valid entries are 1-10");
        bounds = 10;
    }
    int result = scanf("%d", &temp);
    //printf("This is result %d \n",result);

    /**  if the scanf does not read anything, clear from the stdin buffer and return -1*/
    if (result == 0)
    {
        puts("Non-integer input entered. Please enter an integer.\n");
        temp = -1;
    }
    else if (temp < 1)
    {
        puts("Value entered is less than 1");
        temp = -1;
    }
    else if (temp > bounds)
    {
        printf("Value entered is greater than %d\n", bounds);
        temp = -1;
    }
    scanf("%*[^\n]"); //discards the leftover inputs in stdin buffer
    return temp;
}