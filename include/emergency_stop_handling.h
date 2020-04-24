/** @file emergency_stop_handling.h 
 * @brief contains declaration for the emergency_stop_handling() function.
 * 
 * @author Divyalakshmi Padmanaban
**/

#ifndef __EMERGENCY_STOP_HANDLING_H__
#define __EMERGENCY_STOP_HANDLING_H__

#include "structures.h"
#include "globals.h"

extern void emergency_stop_handling(struct elevator ele[],unsigned int *timer);

#endif
