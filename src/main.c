/**
 * @file main.c
 *
 * @brief This function executes the Static and Dynamic version of elevator.
 *
 * @author Maaz Jamal  
 * @author Hariprasad Munusamy
 * @author Divyalakshmi Padmanaban
 * @author Ritika Arora
 *
 */

#include "functions.h"
#include "simulations.h"
#include <stdio.h>

/**
 * @brief This function serves as an entry point into the program. Allows choice between the two versions.
 *
 * @details This finction asks the user for selection between static and dynamic simulation of elevator.
 * 
 * 
 * @return This function returns an integer 0 (Zero) upon successful execution.
 */
int main(void)
{
	int status = 0;
	status = static_simulation();
	status = dynamic_simulation();
	if (status == 1)
	{
		printf("Simulation Run Succesfully.\n");
	}
	return 0;
}
