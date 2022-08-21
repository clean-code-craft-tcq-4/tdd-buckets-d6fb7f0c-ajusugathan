#include <stdio.h>
#include <assert.h>
#include "detectRange.h"
void TEST_CASE_01()
{
    int data_01[2]={4,5};
    static rangeInfo DataForDisplay_01[DISPLAY_SIZE];
    int totalreadings_01=sizeof(data_01)/sizeof(data_01[0]);
    assert(DetectAndDisplayRange(data_01,totalreadings_01) == 1);
    assert(detectRange(data_01,totalreadings_01,DataForDisplay_01)==1);
    assert(DataForDisplay_01[0].rangeStart == 4);
    assert(DataForDisplay_01[0].rangeEnd == 5);
    assert(DataForDisplay_01[0].readingsInRange == 2);
}
void TEST_CASE_02()
{
    int data_02[5]={5,8,4,4,10};
    static rangeInfo DataForDisplay_02[DISPLAY_SIZE];
    int totalreadings_02=sizeof(data_02)/sizeof(data_02[0]);
    assert(DetectAndDisplayRange(data_02,totalreadings_02) == 3);
    assert(detectRange(data_02,totalreadings_02,DataForDisplay_02)==3);
    
    assert(DataForDisplay_02[0].rangeStart == 4);
    assert(DataForDisplay_02[0].rangeEnd == 5);
    assert(DataForDisplay_02[0].readingsInRange == 3);
    
    assert(DataForDisplay_02[1].rangeStart == 8);
    assert(DataForDisplay_02[1].rangeEnd == 0);
    assert(DataForDisplay_02[1].readingsInRange == 1); 
    
    assert(DataForDisplay_02[2].rangeStart == 10);
    assert(DataForDisplay_02[2].rangeEnd == 0);
    assert(DataForDisplay_02[2].readingsInRange == 1);    
}

int main()
{
   TEST_CASE_01();
   TEST_CASE_02();
   TEST_CASE_03();
}
