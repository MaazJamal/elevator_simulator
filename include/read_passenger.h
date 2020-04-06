  
/**@file read passenger.h 
 * *@brief contains declaration for structure read_passenger function.
Contains declaration for read_passenger function -Reads the input file for passenger id,arrival time,starting floor and destination floor.

Enables to read the data from file and store in a structure of maximum capacity 100.

The function  defination is found in read_passeneger.c 
*/
#ifndef __READ_PASSENGER_H__
#define __READ_PASSENGER_H__
#include "structures.h"

extern int read passenger(struct passenger*p);

#endif
