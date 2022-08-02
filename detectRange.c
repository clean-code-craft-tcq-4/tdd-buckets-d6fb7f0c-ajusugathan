#include <stdio.h>
#include "detectRange.h"

int detectRange(int * reading,int size,rangeInfo *Data_struct)
{
    int totalRange=0;
    Data_struct[totalRange].rangeStart=reading[0];
	  Data_struct[totalRange].readingsInRange=1;
    for(int i=0;i<size-1;i++)
    {
       if((reading[i]+1==reading[i+1])||(reading[i]==reading[i+1]))
       {

       Data_struct[totalRange].rangeEnd=reading[i+1];
       Data_struct[totalRange].readingsInRange++;
       }
       else
       {
       totalRange++;
       Data_struct[totalRange].rangeStart=reading[i+1];
       Data_struct[totalRange].readingsInRange++;
       }
    }
	  return(totalRange+1);
}

void printRangeInfo(rangeInfo *Data_struct,int totalRange)
{
    printf("\nRange         Count\n");
    for(int i=0;i<totalRange;i++)
    {
         if(Data_struct[i].readingsInRange != 1)
         {
           printf("%d - %d , %d\n",Data_struct[i].rangeStart, Data_struct[i].rangeEnd,Data_struct[i].readingsInRange);
         }
         else
         {
            printf("%d , %d\n",Data_struct[i].rangeStart,Data_struct[i].readingsInRange); 
         }
    }

}
