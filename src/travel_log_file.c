/** @file travel_log_file.c
 * 
 * @brief Contains the deifintion of travel_log_file() this function writes useful
 * logs about the travel of the passengers.
 * 
 * @author Maaz Jamal
 * */

#include "travel_log_file.h"
#include "structures.h"
#include <stdlib.h>
#include <stdio.h>
#include "average_waiting_time.h"
#include "max_waiting_time.h"
#include <stdbool.h>


/** This function generates and updates the outputput files for data processin
 * 
 * This function generates the output file waiting_times.txt and travel_log.txt which
 * contain the average and max waiting time, and the user_id,elevator_id, passenger arrival time 
 * passenger leaving time.
 * 
 * @param [in] traveler struct containing details about the passenger
 * @param [in] event_time the time the event to be recorded happened.
 * @param [in] elevator_index the index of the elevator the passenger was in.
 * @param [in] mode 1 for writing to travel_log.txt, 2 for calculating average and max time,3 for writing waiting_times.txt log file)
 * 
 * @return does not return an value
 * */
void travel_log_file(struct passenger traveler,unsigned int event_time, int elevator_index, int mode){
	
	static bool first_call = true; //! This keeps track if the output path file is being opened for first time  
	char * travel_file_path = "data/travel_log.txt"; //! relative path to the travel_log.txt file path
	char * waiting_times_files_path = "data/waiting_times.txt"; //relative path to waiting_times.txt file path 
	FILE *f;
	float diff;
	switch (mode){
	
	case 1:	//This case is to write to travel_log file
		if(first_call){
			f = fopen(travel_file_path,"w+");
			if (f == NULL){
			fprintf(stderr,"Could not create/open travel_log.txt file.\n");
			exit(-1);	
			}
			first_call = false;
			fprintf(f,"Passenger_ID,Elevator_ID,Passenger_In_time,Passenger_Entry_floor,Passenger_Out_time,Passenger_Exit_floor\n");
		}
		else{
			f = fopen(travel_file_path,"a+");
			if (f == NULL){
			fprintf(stderr,"Could not create/open travel_log.txt file.\n");
			exit(-1);	
			}
		}
		
		int id = traveler.id;
		int in_time = traveler.arrival_time;
		int in_floor = traveler.arrival_floor;
		int out_floor = traveler.dest_floor;
		fprintf(f,"%d,%d,%d,%d,%d,%d\n",id,elevator_index,in_time,in_floor,event_time,out_floor);
		fflush(f);
		fclose(f);
		break;
	case 2:
	//This case is to calculate max and average wait time.
		
		diff = event_time - traveler.arrival_time;
		if(diff < 0.0){
			fprintf(stderr,"Negative time difference.\n");
			exit(-1);
		}
		average_waiting_time(diff);
		max_waiting_time(diff);
		break;
	case 3://This case is to write to waiting time
		f = fopen(waiting_times_files_path,"w+");
		if (f == NULL){
			fprintf(stderr,"Could not create waiting_times.txt file.\n");
			exit(-1);	
			}
		float avg_time = average_waiting_time(-1.0);
		float max_time = max_waiting_time(-1.0);
		fprintf(f,"Average Waiting time of Passenger: %f\n",avg_time);
		fprintf(f,"Maximum Waiting time of Passenger: %f\n",max_time);
		fflush(f);
		fclose(f);
		break;
	default:
		fprintf(stderr,"Incorrect mode selection.");
		exit(-1);
	}
}
