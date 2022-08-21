#include <stdio.h>
#include "detectRange.h"

int * readingSorting(int* inputReading,int size)
{
    int temp_data;
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if(inputReading[i]>inputReading[j])
            {
                temp_data=inputReading[i];
                inputReading[i]=inputReading[j];
                inputReading[j]=temp_data;
            }
        }

    }
    return(inputReading);
}

int detectRange(int * readings,int size,rangeInfo *Data_struct)
{
    int totalRange=0;
    Data_struct[totalRange].rangeStart=readings[0];
    Data_struct[totalRange].readingsInRange=1;
    for(int Readcount=0;Readcount<size-1;Readcount++)
    {
       if((readings[Readcount]+1==readings[Readcount+1])||(readings[Readcount]==readings[Readcount+1]))
       {

       Data_struct[totalRange].rangeEnd=readings[Readcount+1];
       Data_struct[totalRange].readingsInRange++;
       }
       else
       {
       totalRange++;
       Data_struct[totalRange].readingsInRange=0;
       Data_struct[totalRange].rangeStart=readings[Readcount+1];
       Data_struct[totalRange].readingsInRange++;
       }
    }
	  return(totalRange+1);
}

void printRangeInfo(rangeInfo *Data_struct,int totalRange)
{
    printf("\nRange         Count\n");
    for(int Rangecount=0;Rangecount<totalRange;Rangecount++)
    {
         if(Data_struct[Rangecount].readingsInRange != 1)
         {
           printf("%d - %d , %d\n",Data_struct[Rangecount].rangeStart, Data_struct[Rangecount].rangeEnd,Data_struct[Rangecount].readingsInRange);
         }
         else
         {
            printf("%d , %d\n",Data_struct[Rangecount].rangeStart,Data_struct[Rangecount].readingsInRange); 
         }
    }

}
int DetectAndDisplayRange(int * readings,int totalData)
{
    int CheckedRanges;
    static rangeInfo DataForDisplay[DISPLAY_SIZE];
    CheckedRanges=detectRange(readingSorting(readings,totalData),totalData,DataForDisplay);
    printRangeInfo(DataForDisplay,CheckedRanges);
    return(CheckedRanges);
}
