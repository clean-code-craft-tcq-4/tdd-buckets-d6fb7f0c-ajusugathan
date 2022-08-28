#include <stdio.h>
#include <assert.h>
#include "detectRange.h"
void TEST_CASE_01()
{
    int data_01[2]={4,5};
    static rangeInfo DataForDisplay_01[DISPLAY_SIZE];
    int totalreadings_01=sizeof(data_01)/sizeof(data_01[0]);
    assert(DetectAndDisplayRange(data_01,totalreadings_01) == 1);
    assert(detectRange(readingSorting(data_01,totalreadings_01),totalreadings_01,DataForDisplay_01)==1);
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
    assert(detectRange(readingSorting(data_02,totalreadings_02),totalreadings_02,DataForDisplay_02)==3);
    
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

void TEST_CASE_03()
{
    int data_03[6]={3,15,11,1,2,23};
    static rangeInfo DataForDisplay_03[DISPLAY_SIZE];
    int totalreadings_03=sizeof(data_03)/sizeof(data_03[0]);
    assert(DetectAndDisplayRange(data_03,totalreadings_03) == 4);
    assert(detectRange(readingSorting(data_03,totalreadings_03),totalreadings_03,DataForDisplay_03)==4);
    
    assert(DataForDisplay_03[0].rangeStart == 1);
    assert(DataForDisplay_03[0].rangeEnd == 3);
    assert(DataForDisplay_03[0].readingsInRange == 3);
    
    assert(DataForDisplay_03[1].rangeStart == 11);
    assert(DataForDisplay_03[1].rangeEnd == 0);
    assert(DataForDisplay_03[1].readingsInRange == 1); 
    
    assert(DataForDisplay_03[2].rangeStart == 15);
    assert(DataForDisplay_03[2].rangeEnd == 0);
    assert(DataForDisplay_03[2].readingsInRange == 1);  
    
    assert(DataForDisplay_03[3].rangeStart == 23);
    assert(DataForDisplay_03[3].rangeEnd == 0);
    assert(DataForDisplay_03[3].readingsInRange == 1); 
}

int main()
{
   TEST_CASE_01();
   TEST_CASE_02();
   TEST_CASE_03();
}
