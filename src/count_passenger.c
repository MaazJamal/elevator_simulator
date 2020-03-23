#include<stdio.h>
#include<stdlib.h>
int count_passenger()
{
    int passenger_count=0;
    FILE *f;
    char a[10];
    f=fopen("D:\\Software in C\\fwdinputfiles\\input.txt","r");
    while(fscanf(f,"%s",a)!=EOF)
    {
        passenger_count++;
    }
    fclose(f);
    return passenger_count/4;
}

