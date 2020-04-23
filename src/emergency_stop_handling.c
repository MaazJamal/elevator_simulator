#include<stdio.h>
#include<stdbool.h>
#include"structures.h"
#include"globals.h"
#include"emergency_stop_handling.h"
/**
 * @file emergency_stop_handling.c
 *
 * @brief On account of emergency stop condition,All the elevators re moved to nearest floor.
 * Passengers are removed from the elevators.
 *
 * @author Divyalakshmi Padmanaban  - dpadm049@uottawa.ca	
 *
 * @param[in] The function takes elevator strucrure and the currect time index of the simulation
 * 
 * @return The function returns nothing, takes all the lift to next floor and removes all passenger from elevator
 */
void emergency_stop_handling(struct elevator ele[],int *timer)
{
	int i,j,k=0;
	int count;
	bool status=true;
	while(status)
	{
	
	for(i=0;i<elevator_count;i++)
	{   
		    
		    if(ele[i].passenger_count>=1)
		    {
		        if((ele[i].moving==1)&&(ele[i].between_floor==1))
		        {
			        if(ele[i].direction_up==true)
			        {
				        for(j=0;j<ele[i].max_passenger;j++)
				        {
				            ele[i].passsenger_arr[j].dest_floor=ele[i].cur_floor+1;
				            ele[i].moving=k;
				            ele[i].between_floor=k;
				            passengers_drop(ele[i],i,ele[i].cur_floor,ele[i].timer);
			            }
			        }
			        if(ele[i].direction_down==true)
			        {
				        for(j=0;j<ele[i].max_passenger;j++)
				        {
				            ele[i].passsenger_arr[j].dest_floor=ele[i].cur_floor-1;
				            ele[i].moving=k;
				            ele[i].between_floor=k;
				            //remove_passenger_floor(ele[i].passenger_arr[j]);
				            passengers_drop(ele[i],i,ele[i].cur_floor,ele[i].timer);
			            }
			        }
			
	         	}
	        }
		
    }
		timer++;
	for(i=0;i<elevator_count;i++)
	{
		if(ele[i].passenegr_count!=0)
		{
			status=true;
			break;
		}
		if(ele[i].passenger_count==0){
			status=false;
		}
		
	}

    }
}
