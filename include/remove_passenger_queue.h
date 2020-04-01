/** 
 * @file remove_passenger_queue.h
 * contains the declaration for remove_passenger_queue function that remoove passenger from 
 * a queue, either floor queue or request queue. 
 * */

#ifndef __REMOVE_PASSENGER_QUEUE_H__
#define __REMOVE_PASSENGER_QUEUE_H__

#include "structures.h"

extern struct passenger* remove_passenger_queue(int index, struct passenger* head);

#endif