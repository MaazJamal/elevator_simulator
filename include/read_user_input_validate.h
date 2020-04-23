/**
 * @file read_user_input_validate.h
 *
 * @author Ritika Arora
 *
 * @brief contains declarations for read_user_input_validate function. Reads the passenger
 * information from the user console and adds it to the passenger structure after validating
 *
 * @param[in] passenger_info pointer to the passenger structure containing data of the passenger.
 * @param[in] timer to get the time of simulation and store as time of arrival
 *
 * @return void returns nothing
*/
#ifndef __READ_USER_INPUT_VALIDATE_H__
#define __READ_USER_INPUT_VALIDATE_H__
#include "structures.h"
#include "globals.h"

extern void read_user_input_validate(struct passenger *passenger_info, unsigned int timer);

#endif
