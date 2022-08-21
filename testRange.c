#include <stdio.h>
#include <assert.h>
#include "detectRange.h"

void TEST_CASE_01()
{
    int data[2]={4,5};
    static rangeInfo DataForDisplay[DISPLAY_SIZE];
    int totalreadings=sizeof(data)/sizeof(data[0]);
    assert(DetectAndDisplayRange(data,totalreadings) == 1);
    assert(detectRange(data,totalreadings,DataForDisplay)==1);
    assert(DataForDisplay[0].rangeStart == 4);
    assert(DataForDisplay[0].rangeEnd == 5);
    assert(DataForDisplay[0].readingsInRange == 2);
}
void TEST_CASE_02()
{
    int data[5]={5,8,4,4,10};
    static rangeInfo DataForDisplay[DISPLAY_SIZE];
    int totalreadings=sizeof(data)/sizeof(data[0]);
    assert(DetectAndDisplayRange(data,totalreadings) == 3);
    assert(detectRange(data,totalreadings,DataForDisplay)==3);
    
    assert(DataForDisplay[0].rangeStart == 4);
    assert(DataForDisplay[0].rangeEnd == 5);
    assert(DataForDisplay[0].readingsInRange == 3);
    
    assert(DataForDisplay[1].rangeStart == 8);
    assert(DataForDisplay[1].rangeEnd == 0);
    assert(DataForDisplay[1].readingsInRange == 1); 
    
    assert(DataForDisplay[2].rangeStart == 10);
    assert(DataForDisplay[2].rangeEnd == 0);
    assert(DataForDisplay[2].readingsInRange == 1);    
}

void TEST_CASE_03()
{
    int data2[6]={3,8,10,1,2,23};
    static rangeInfo DataForDisplay[DISPLAY_SIZE];
    int totalreadings=sizeof(data2)/sizeof(data2[0]);
    assert(DetectAndDisplayRange(data2,totalreadings) == 4);
    assert(detectRange(data,totalreadings,DataForDisplay)==4);
    
    assert(DataForDisplay[0].rangeStart == 1);
    assert(DataForDisplay[0].rangeEnd == 3);
    assert(DataForDisplay[0].readingsInRange == 3);
    
    assert(DataForDisplay[1].rangeStart == 8);
    assert(DataForDisplay[1].rangeEnd == 0);
    assert(DataForDisplay[1].readingsInRange == 1); 
    
    assert(DataForDisplay[2].rangeStart == 10);
    assert(DataForDisplay[2].rangeEnd == 0);
    assert(DataForDisplay[2].readingsInRange == 1);  
    
    assert(DataForDisplay[2].rangeStart == 23);
    assert(DataForDisplay[2].rangeEnd == 0);
    assert(DataForDisplay[2].readingsInRange == 1); 
}

int main()
{
   TEST_CASE_01();
   TEST_CASE_02();
   TEST_CASE_03();
}
