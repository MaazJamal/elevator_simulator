#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"read_passenger.h"
#include"structures.h"
/**
Reads the input file for passenger id,arrival time,starting floor and destination floor.

Enables to read the data from file and store in a structure of maximum capacity 100.

Constraints
If the file does not exists ,the function displays a error message.

The input file is checked for valid values for passenegr id in range (1-99) and print error message if the values are out of range.

The input file is checked for valid values for arrival time in range (1-150)and print error message if the values are out of range

The input file is checked for valid values for arrival floor in range (1-100)and print error message if the values are out of range

The input file is checked for valid values for destination floor in range (1-100)and print error message if the values are out of range


**/
void read_passenger(struct passenger p[])
{

    FILE *f;
    int i=0;
    int count=0;
    f=fopen("data/input.txt","r");
    int fd = fileno(f);//fileno function returns the mode of file.
    if(fd==-1)
    {
    	printf("Error - input file\n");
    	exit(1);//program ends incase of absence of file in specified path. 
	}
    if (f==NULL) 
    { 
        printf("Error -opening the file\n"); 
        exit(1); //program ends incase of error in opening the  input file.
    } 
   
    if (NULL != f) 
	{
	 int size;
    fseek (f, 0, SEEK_END);
    size = ftell(f);
   

    if (0 == size) 
	{
        printf("Input file is empty\n");
        exit(1);
    }
    }
    rewind(f);
    
   
   
    char c[100];
    while(fscanf(f,"%s",c)!=EOF)
    {
    	
	//	printf("%s",c,);
	    
		if(count==0)
		{
			
			p[i].id=atoi(c);
			count++;
			if((p[i].id==0)||(p[i].id<1))
			{
				printf("p[%d] -Passenger ID column contains invalid data in  file (i.e)%d\n",i,p[i].id);
				exit(1);//program ends incase of erraneous data.
			}
		
		}
			
		else if(count==1)
		{
		
			p[i].arrival_time=atoi(c);
			count++;
			if((p[i].arrival_time==0)||(p[i].arrival_time>86400)||(p[i].arrival_time<1))
			{
				printf("p[%d].-arrival_time column contains invalid data in file (i.e)%d\n",i,p[i].arrival_time);
				exit(1);//program ends incase of erraneous data.
			}
		}
		else if(count==2)
		{
		
		    p[i].arrival_floor=atoi(c);
		    count++;
		    if((p[i].arrival_floor==0)||(p[i].arrival_floor>100)||(p[i].arrival_floor<1))
		    {
				printf("p[%d].arrival_floor column contains invalid data  in file (i.e)%d\n",i,p[i].arrival_floor);
				exit(1);//program ends incase of erraneous data.
			}
		}	
		else if(count==3)
		{
			//printf("\n%s\n",c);
		p[i].dest_floor=atoi(c);
		count=0;
		if((p[i].dest_floor==0)||(p[i].dest_floor>100)||(p[i].dest_floor<1))
		{
			printf("p[%d].dest_floor column contains invalid data in  file (i.e)%d\n",i,p[i].dest_floor);
			exit(1);//program ends incase of erraneous data.
		}
		i++;
	   }
		    
	   }	
	
	printf("read_passenger is executed-Size of array of structure passenger is %d \n",i);
    fclose(f);
	printf("Input file is closed-read_passenger function\n");
	
}
