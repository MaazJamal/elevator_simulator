/** @file test_main.c
 * 
 * @brief serves as an entry point for the test_cases functions. 
 * 
 * */
#include <stdio.h>
#include "test_functions.h"

extern void test_cases();

int main(){
	printf("Running Test Cases Program.\n");
	test_cases();
	return 0;
}