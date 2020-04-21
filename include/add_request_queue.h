/** @file add_request_queue.h 
 *@brief contains declarations for add_request_queue function. Used to add 
 * passenger to queue
 * 
 * @author Maaz Jamal 
*/
#ifndef __ADD_REQUEST_QUEUE_H__
#define __ADD_REQUEST_QUEUE_H__

#include "structures.h"

extern struct passenger* add_request_queue(struct passenger* head, struct passenger passenger_queue);

#endif