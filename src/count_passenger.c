/**
 * @file count_passenger.c
 *
 * @brief Reads line by line and counts the number of passenger based on passenger ID.
 * When passenger ID equal to "911" it is considered as Emergency stop and wont be counted towards the passenger_count.
 *
 * @author Hariprasad Munusamy  - HariprasadMunusamy@cmail.carleton.ca	
 *
 */
#include<stdio.h>
#include<stdlib.h>
#include "count_passenger.h"
#include "globals.h"
#include "structures.h"

/** @details Counts the passenger requests
 *
 * @param[in] No input parameter. The function uses the input file
 *
 * @return Returns count on successful execution and 0 if file doesn't exist.
 *
 */
int count_passenger()
{
    /**  es to store the number of emergency stop situations*/
    int es=0;
    passenger_count=0; //global variable stores the passenger count
    FILE *f;
    char a[10];
    f=fopen("data/input.txt","r");
    if (f==NULL) 
    { 
        printf("no input file exists"); 
        return 0; 
    }
    while(fscanf(f,"%s",a)!=EOF)
    {
        if((passenger_count==0)||(passenger_count%4)==0)
        {
            if(atoi(a)==911)
            {
            es++;
            }
        }
        passenger_count++;
    }
    fclose(f);
    passenger_count=passenger_count/4;
    passenger_count=passenger_count-es;
    return passenger_count;  //returns the passenger count
}


