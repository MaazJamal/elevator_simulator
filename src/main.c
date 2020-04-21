/*
 * @file main.c
 *
 * @brief This function executes the Static and Dynamic version of elevator and performs Unit testing
 *
 * @author Maaz Jamal - maazjamal@cmail.carleton.ca
 * @author Hariprasad Munusamy  - HariprasadMunusamy@cmail.carleton.ca
 * @author Divyalakshmi Padmanaban  - Dpadm049@uottawa.ca
 * @author Ritika Arora - ritikaarora@cmail.carleton.ca
 *
 */
 
#include "functions.h"
#include "simulations.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

/*
 * 
 *
 * @details This function takes the argument from user to perform testing,static and dynamic version of elevator and calls calls the associated function.
 * h : Help Information
 * t : Performs unit testing
 * e : Performs elevator simlation
 *
 * @return This function returns an integer 0 (Zero) upon successful execution.
 */
int main(int argc, char *argv[]){
	int opt;

	while ((opt = getopt(argc, argv, "het")) != -1){

		switch(opt){
            		case 'h':
                		printf("-t Runs automated unit testing and exits\n");
                		printf("-e Runs main program elevator simulation and exits\n");
                		return 0;
                		break;
            		case 't':
                		/* Run automated unit testing */
                		printf("Running automated unit testing\n");
                		test_cases();
                		printf("Automated testing has completed\n");
                		return 0;
               			break;
            		case 'e':
                		/* Main Elevator simulation program */
                		printf("Running Elevator Simulation Program\n");
                		int elevator_version=input_static_dynamic();
                		if(elevator_version==1)
                		{
                			//dynamic_simulation;
                			return 0;
						}
						if(elevator_version==0)
						{
							static_simulation();
							return 0;
						}
						break;
						default:
							printf("Invalid argument \n");
							return 0;
					}
	}
					
	
}

