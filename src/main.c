/**
 * @file main.c
 *
 * @brief This function executes the Static and Dynamic version of elevator and performs Unit testing
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
 * 
 *
 * @details This function serves as an entry point into the program.
 * 
 * @return This function returns an integer 0 (Zero) upon successful execution.
 */
int main(void)
{
	int status = 0;
	//status = static_simulation();
	status = dynamic_simulation();
	if (status == 1)
	{
		printf("Simulation Run Succesfully.\n");
	}
	return 1;
}
