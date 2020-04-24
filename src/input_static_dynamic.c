#include "../include/input_static_dynamic.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @file input_static_dynamic.c
 *
 * @Author Ritika Arora
 *
 * @brief Prompts user for type of simulation they want to run.
 *
 * @detail Asks user the type of simulation he wants to run. For, static, he has to press 1 and
 * for dynamic, he has to press 2. If 1 is entered by the user, then it will assign 0 to the
 * local variable simulation_type. If 2 is entered, then it assigns 1 to the variable.
 *
 * @param[in] void The function takes no inputs
 *
 * @param[out] simulation_type contains the value to be returned to decide which type of
 * simulation runs.
 *
 * @return int Returns 0 for static simulation, 1 for dynamic simulation and -1 for invalid input.
 *
*/
int input_static_dynamic(void){
   int input,simulation_type;
   printf("What type of simulation you want to run? \n Press 1 for Static or 2 for Dynamic?\n");
   scanf("%d", &input);
   if (input == 1){
	   simulation_type = 0;
   }
   else if (input ==2){
	   simulation_type = 1;
   }
   else{
	   printf("Entered invalid value.");
	   simulation_type = -1;
   }
   scanf("%*[^\n]");
   return simulation_type;
}
