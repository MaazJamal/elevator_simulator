#include <stdbool.h>
#include "structures.h"

/** 
 * \brief structure for to store important information about a passenger.
 * 
 * Stores the arrival time and floor and destination floor of the passenger.
 * as well as the passenger id. There is a next passenger pointer to create queues
 */

struct passenger{
unsigned int	arrival_time; //!< stores arrival time of the passenger
unsigned int	arrival_floor; //!< stores the arrival_floor of the passenger
unsigned int	dest_floor; //!< stores the destination floor of the passenger
unsigned int 	id; //!< stores the passenger_id of the passenger
struct passenger* next; //! stores address of the next node in case of creation of queues
};

/** 
 * \brief structure for to store important information about a elevator.
 * 
 * Stores information about the elevator such as direction of travel,
 * the floors to stop at. The maximum number of passengers the lift can accomodate 
 * and the current passengers in the lift and their information.
 * and time it takes to go to the reach next floor. 
 */

struct elevator{
bool	moving; //! Is the elevator moving? True 1 or False(stationary) 0.
bool	between_floor; //! Is elevator between floors. True 1 between floors.
bool	direction_up; //! Is the elevator going up? True 1 for going up
bool	direction_down; //! Is the elevator going down? True 1 for going down
bool    *stop_at_floor; //! points to boolean array of floors and shows if the elevator will stop at a certain floor or not.
unsigned int	passenger_count; //! count of passenger occupying the elevator
unsigned int	max_passenger; //! Maximum number of passengers the lift can accomodate
unsigned int	cur_floor; //!
unsigned int 	timer; //! Time clock untill the next floor
struct passenger *passenger_arr; //! points to a array of struct pasenger of size max_passenger.   
};

/** 
 * \brief a linked list that will be used to form a queue of passenger requests.
 */

