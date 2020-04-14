#include<stdio.h>
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
    f=fopen("C:\\bigfloor.txt","r");
    int fd = fileno(f);//fileno function returns the mode of file.
    if(fd==-1)
    {
    	printf("Error - input file\n");
    	exit(1);//program ends incase of absence of file in specified path. 
	}
    if (f==NULL) 
    { 
        printf("Input file is empty\n"); 
        exit(1); //program ends incase of empty input file.
    } 
   
   
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
				printf("p[%d]contains invalid data stored from file (i.e)%d\n",i,p[i].id);
				exit(1);//program ends incase of erraneous data.
			}
		
		}
			
		else if(count==1)
		{
		
			p[i].arrival_time=atoi(c);
			count++;
			if((p[i].arrival_time==0)||(p[i].arrival_time>86400)||(p[i].arrival_time<1))
			{
				printf("p[%d].arrival_time contains invalid data stored from file (i.e)%d\n",i,p[i].arrival_time);
				exit(1);//program ends incase of erraneous data.
			}
		}
		else if(count==2)
		{
		
		    p[i].arrival_floor=atoi(c);
		    count++;
		    if((p[i].arrival_floor==0)||(p[i].arrival_floor>100)||(p[i].arrival_floor<1))
		    {
				printf("p[%d].arrival_floor contains invalid data stored from file (i.e)%d\n",i,p[i].arrival_floor);
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
			printf("p[%d].dest_floor contains invalid data stored from file (i.e)%d\n",i,p[i].dest_floor);
			exit(1);//program ends incase of erraneous data.
		}
		i++;
	   }
		    
	   }	
	
	fclose(f);
	printf("Input file is closed-read_passenger function\n");
}
