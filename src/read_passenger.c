#include<stdio.h>
#include"read_passenger.h"
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
    f=fopen("datafolder\inputfile.txt","r");
    int fd = fileno(f);
    if(fd==-1)
    {
    	printf("Error - input file");
    	return 0;
	}
    if (f==NULL) 
    { 
        printf("Input file is empty"); 
        return 0; 
    } 
   
    int count=0;
    char c[10];
    
    struct passengers p[100];
    while(fscanf(f,"%s ",c)!=EOF)

	{
	//	printf("%s",c,);
		if(count==0)
		{
			//printf("\n%s",c);
			if((p[i].id!=0)&&(p[i].id>=1))
			{
				p[i].id=atoi(c);
			    count++;
			}
			else
			{
				printf("File contains invalid data for passenger id");
			}
			
		}
		else if(count==1)
		{
			if((p[i].arrival_time!=0)&&(p[i].arrival_time<=86400)&&(p[i].arrival_time>=1))
			{
			p[i].arrival_time=atoi(c);
			count++;
		    }
		    else
		    {
		    	printf("File contains invalid data for arrival time");
			}
		}
		else if(count==2)
		{
			if((p[i].arrival_floor!=0)&&(p[i].arrival_floor<101)&&(p[i].arrival_floor>=1))
			{
				p[i].arrival_floor=atoi(c);
			    count++;
			}
			else
			{
				printf("File contains invalid data for arrival floor");
			}
			
		}	
		else if(count==3)
		{
			//printf("\n%s\n",c);
			if((p[i].dest_floor!=0)&&(p[i].dest_floor<101)&&(p[i].dest_floor>=1))
			{
			p[i].dest_floor=atoi(c);
			count=0;
			i++;
		    }
		    else
			{
				printf("File contains invalid data for destination floor");
			}
		}	
	}
	fclose(f);
	printf("Input file is closed-read_passenegr function");
   // printf("%d",p[0].pid);
}
