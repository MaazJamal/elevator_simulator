#include "../include/read_user_input_validate.h"
#include "../include/globals.h"
#include "../include/structures.h"
#include <stdlib.h>
#include <stdio.h>
//#include <time.h>


/**
 * @file read_user_input_validate.c
 *
 * @author Ritika Arora
 *
 * @brief Reads the input from the console and adds to the passenger struct after validating.
 *
 * @details Reads the passenger details from the user console. Validates the inputs given.
 * Then, adds the inputs taken to the passenger structure
 *
 * @param[in] passenger_info pointer to the passenger structure containing data of the passenger.
 * @param[in] timer to get the time of simulation and store as time of arrival
 *
 * @return void returns nothing
*/
void read_user_input_validate(struct passenger *passenger_info, unsigned int timer){


    int arrival_floor, dest_floor, passenger_id; // local variables to get the values from user and store them in the structure

    int correct_id = 0, correct_arrival_floor = 0, correct_dest_floor = 0; //variable to check if correct input is given by the user

        printf("Enter the id");

        while( correct_id == 0){
                while((scanf("%d",&passenger_id))==0){
                //To check that user enters an integer value only
                scanf("%*[^\n]");
                printf("Invalid entry, please enter a valid number: ");
                }

                if(passenger_id <=0){
                    printf("Invalid passenger id entered");
                    correct_id == 0;
                    continue;
                }
                correct_id = 1;
        }
        printf("Enter the arrival floor between 1 and %d:",floor_count);

        while( correct_arrival_floor == 0){
                while((scanf("%d",&arrival_floor))==0){
                //To check that user enters an integer value only
                scanf("%*[^\n]");
                printf("Invalid entry, please enter a valid number: ");
                }

                if(arrival_floor<=0 || arrival_floor > floor_count){
                    printf("Invalid arrival floor entered!!");
                    correct_arrival_floor == 0;
                    continue;
                }
                correct_arrival_floor = 1;
        }

        printf("Enter the destination floor between 1 and %d:",floor_count);

        while( correct_dest_floor == 0){
                while((scanf("%d",&dest_floor))==0){
                //To check that user enters an integer value only
                scanf("%*[^\n]");
                printf("Invalid entry, please enter a valid number: ");
                }

                if(dest_floor<=0 || dest_floor > floor_count){
                    printf("Invalid arrival floor entered!!");
                    correct_dest_floor == 0;
                    continue;
                }
                correct_dest_floor = 1;
        }
    passenger_info.id = passenger_id;
    passenger_info.arrival_floor = arrival_floor;
    passenger_info.dest_floor = dest_floor;
    passenger_info.arrival_time = timer;

//    printf("Passenger details entered are:\n");
//    printf("Id:%d\n",passenger_info.id);
//    printf("Arrival Floor:%d\n",passenger_info.arrival_floor);
//    printf("Destination floor:%d\n",passenger_info.dest_floor);
//    printf("Arrival Time:%d\n",passenger_info.arrival_time);

}



