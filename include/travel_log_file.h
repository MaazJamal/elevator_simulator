/** @file travel_log_file.h
 * @brief contains the function declaration for travel_log_file() function
 * which writes the travel history of passenger in the lift.
 * */

#ifndef __TRAVEL_LOG_FILE_H__
#define __TRAVEL_LOG_FILE_H__
#include "structures.h"

extern void travel_log_file(struct passenger traveler,unsigned int event_time, int elevator_index, int mode);

#endif