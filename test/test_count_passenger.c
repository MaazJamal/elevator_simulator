#include<stdio.h>
#include<stdlib.h>

void test_count_passenger(void)
{
    FILE *f1,*f2,*f3,*f4,*f5,*f6,*f7,*f8,*f9,*f10;
	f1=fopen("test/data/countpassenger_testcase1.txt","r");
	f2=fopen("test/data/countpassenger_testcase2.txt","r");
	f3=fopen("test/data/countpassenger_testcase3.txt","r");
	f4=fopen("test/data/countpassenger_testcase4.txt","r");
	f5=fopen("test/data/countpassenger_testcase5.txt","r");
	f6=fopen("test/data/countpassenger_testcase6.txt","r");
	f7=fopen("test/data/countpassenger_testcase7.txt","r");
	f8=fopen("test/data/countpassenger_testcase8.txt","r");
	f9=fopen("test/data/countpassenger_testcase9.txt","r");
	f10=fopen("test/data/countpassenger_testcase10.txt","r");
	FILE* test_result = fopen("test/results/results_count_passenger.txt", "w");
	int count;
	//Test case 1 - Input file not present in path
	count=count_passenger(f1);
	if (count == -1)
	{
        char t[100];
        sprintf(t,"1)PASS: Input: Invlaid file, Expected Output: -1, Output: %d .\n",count);
        printf(t);
        fprintf(test_result,t);        
    }
    else
	{
        char t[100];
        sprintf(t,"1)FAIL: Input: Invalid file, Expected Output: -1, Output: %d .\n",count);
        printf(t);
        fprintf(test_result,t);
    }
    //Test case 2 - Empty Input file
	count=count_passenger(f2);
	if (count == 0)
	{
        char t[100];
        sprintf(t,"2)PASS: Input: Empty file, Expected Output: 0, Output: %d .\n",count);
        printf(t);
        fprintf(test_result,t);        
    }
    else
	{
        char t[100];
        sprintf(t,"2)FAIL: Input: Empty file, Expected Output: 0, Output: %d .\n",count);
        printf(t);
        fprintf(test_result,t);
    }
    //Test case 3 - Valid file
	count=count_passenger(f3);
	if (count == 37)
	{
        char t[100];
        sprintf(t,"3)PASS: Input: valid file, Expected Output: 37, Output: %d .\n",count);
        printf(t);
        fprintf(test_result,t);        
    }
    else
	{
        char t[100];
        sprintf(t,"3)FAIL: Input: Empty file, Expected Output: 37, Output: %d .\n",count);
        printf(t);
        fprintf(test_result,t);
    }
    //Test case 4 - Varying the Passenger ID with many possible integers of varying length
	count=count_passenger(f4);
	if (count == 44)
	{
        char t[100];
        sprintf(t,"4)PASS: Input: Varying Passenger ID in file, Expected Output: 44, Output: %d .\n",count);
        printf(t);
        fprintf(test_result,t);        
    }
    else
	{
        char t[100];
        sprintf(t,"4)FAIL: Input: Varying Passenger ID in file,  Expected Output: 44, Output: %d .\n",count);
        printf(t);
        fprintf(test_result,t);
    } 
	//Test case 5 - Repeating the Passenger ID 
	count=count_passenger(f5);
	if (count == 41)
	{
        char t[100];
        sprintf(t,"5)PASS: Input: Repeating the Passenger ID, Expected Output: 41, Output: %d .\n",count);
        printf(t);
        fprintf(test_result,t);        
    }
    else
	{
        char t[100];
        sprintf(t,"5)FAIL: Input: Repeating the Passenger ID,  Expected Output: 41, Output: %d .\n",count);
        printf(t);
        fprintf(test_result,t);
    }  
	//Test case 6 - Giving Character strings to Passenger ID 
	count=count_passenger(f6);
	if (count == 34)
	{
        char t[100];
        sprintf(t,"6)PASS: Input: Giving Character strings to Passenger ID , Expected Output: 34, Output: %d .\n",count);
        printf(t);
        fprintf(test_result,t);        
    }
    else
	{
        char t[100];
        sprintf(t,"6)FAIL: Input: Giving Character strings to Passenger ID ,  Expected Output: 34, Output: %d .\n",count);
        printf(t);
        fprintf(test_result,t);
    }  
	//Test case 7 - Giving Emergency stop situtation 911 to Passenger ID - Count ignores 911
	count=count_passenger(f7);
	if (count == 35)
	{
        char t[100];
        sprintf(t,"7)PASS: Input: Giving Emergency stop situtation 911 to Passenger ID - Count ignores 911 , Expected Output: 35, Output: %d .\n",count);
        printf(t);
        fprintf(test_result,t);        
    }
    else
	{
        char t[100];
        sprintf(t,"7)FAIL: Input: Giving Emergency stop situtation 911 to Passenger ID - Count ignores 911,  Expected Output: 35, Output: %d .\n",count);
        printf(t);
        fprintf(test_result,t);
    }   
    //Test case 8 - Giving Emergency stop situtation 911 to Timestamp - Count should include the record 
	count=count_passenger(f8);
	if (count == 36)
	{
        char t[200];
        sprintf(t,"8)PASS: Input: Giving Emergency stop situtation 911 to Timestamp - Count should include the record, Expected Output: 36, Output: %d .\n",count);
        printf(t);
        fprintf(test_result,t);        
    }
    else
	{
        char t[100];
        sprintf(t,"8)FAIL: Input: Giving Emergency stop situtation 911 to Timestamp - Count should include the record,  Expected Output: 36, Output: %d .\n",count);
        printf(t);
        fprintf(test_result,t);
    } 
	//Test case 9 - Giving Emergency stop situtation 911 to Start floor - Count should include the record 
	count=count_passenger(f9);
	if (count == 37)
	{
        char t[100];
        sprintf(t,"9)PASS: Input: Giving Emergency stop situtation 911 to Start floor - Count should include the record, Expected Output: 37, Output: %d .\n",count);
        printf(t);
        fprintf(test_result,t);        
    }
    else
	{
        char t[100];
        sprintf(t,"9)FAIL: Input: Giving Emergency stop situtation 911 to Start floor - Count should include the record,  Expected Output: 37, Output: %d .\n",count);
        printf(t);
        fprintf(test_result,t);
    }  
    //Test case 10 - Giving Emergency stop situtation 911 to Destination floor - Count should include the record 
	count=count_passenger(f10);
	if (count == 37)
	{
        char t[100];
        sprintf(t,"10)PASS: Input: Giving Emergency stop situtation 911 to Destination floor - Count should include the record, Expected Output: 37, Output: %d .\n",count);
        printf(t);
        fprintf(test_result,t);        
    }
    else
	{
        char t[100];
        sprintf(t,"10)FAIL: Input: Giving Emergency stop situtation 911 to Destination floor - Count should include the record,  Expected Output: 37, Output: %d .\n",count);
        printf(t);
        fprintf(test_result,t);
    }
    fflush(test_result);
    fclose(test_result);
    return 0;
}


int count_passenger(char* f)
{
    /**  es to store the number of emergency stop situation*/
    int es=0;
    int passenger_count=0; //global variable stores the passenger count
    char a[10];
    if (f==NULL) 
    { 
        //printf("no input file exists"); 
        return -1; 
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
    return passenger_count;
}

