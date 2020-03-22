#include <stdio.h>
#include "input_lifts.h"

/**
 * Prompt the user to enter the number of lifts and takes the input
 * 
 * The function prompts the user to enter the number of lifts. If the lift
 * is less than or greater than one the function displays an error message 
 * and returns -1. 
 * If the user enters anythin other than a numeric entry. The function displays
 * and error message, discards all inputs in stdin stream and returns -1.
 * If the user enters numeric value. It accepts the only Whole number part of the entry 
 * and returns the entered whole number value.
 * 
 * @return int Returns -1 if errors in input and integer if input is fine. 
 *  */ 
int input_lifts(void){
     
    int temp;
    puts("Please Enter an integer number for the number of Elevator in building.");
    puts("Valid entries are 1-100");
    int result = scanf("%d", &temp);
    printf("This is result %d \n",result);
    
    /**  if the scanf does not read anthing clear the stdin buffer and return -1*/
    if (result == 0){ 
        puts("Non-integer input entered. Please enter an integer.\n");
        temp = -1;
    }
    else if (temp < 1){
        puts("Value entered is less than 1");
        temp = -1;
    }
    else if (temp > 100){
        puts("Value entered is greater than 100");
        temp =  -1;
    }
    scanf("%*[^\n]");  //discards the leftover inputs in stdin buffer
    return temp;
}