/** @file remove_passenger_queue.h 
 * @brief contains the declaration for remove_passenger_queue function that remoove passenger from a queue
 * 
 * @author Maaz Jamal
*/
#ifndef __REMOVE_PASSENGER_QUEUE_H__
#define __REMOVE_PASSENGER_QUEUE_H__

#include "structures.h"
#include "globals.h"

extern struct passenger *remove_passenger_queue(int index, struct passenger *head);

#endif
