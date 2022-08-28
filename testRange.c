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
void TEST_CASE_04()
{
    int data_04[11]={3,15,15,0,11,0,1,2,2,23,0};
    static rangeInfo DataForDisplay_04[DISPLAY_SIZE];
    int totalreadings_04=sizeof(data_04)/sizeof(data_04[0]);
    assert(DetectAndDisplayRange(data_04,totalreadings_04) == 4);
    
    assert(detectRange(readingSorting(data_04,totalreadings_04),totalreadings_04,DataForDisplay_04)==4);
    
    assert(DataForDisplay_04[0].rangeStart == 0);
    assert(DataForDisplay_04[0].rangeEnd == 3);
    assert(DataForDisplay_04[0].readingsInRange == 7);
    
    assert(DataForDisplay_04[1].rangeStart == 11);
    assert(DataForDisplay_04[1].rangeEnd == 0);
    assert(DataForDisplay_04[1].readingsInRange == 1); 
    
    assert(DataForDisplay_04[2].rangeStart == 15);
    assert(DataForDisplay_04[2].rangeEnd == 15);
    assert(DataForDisplay_04[2].readingsInRange == 2);  
    
    assert(DataForDisplay_04[3].rangeStart == 23);
    assert(DataForDisplay_04[3].rangeEnd == 0);
    assert(DataForDisplay_04[3].readingsInRange == 1); 
}

void TEST_CASE_05()
{
    int data_05[7]={10,1024,800,4090,500,3050,5000};
    int Output_05[7];
    returnData returnData_05;
    returnData_05=DtoA_ConversionArray(&data_05[0],&Output_05[0],7,10);
    assert(returnData_05.value_status==ALL_VALUE_NOTOK);
    assert(returnData_05.outputArrayCount==6);
    
    static rangeInfo DataForDisplay_05[DISPLAY_SIZE];
    assert(DetectAndDisplayRange(&Output_05[0],returnData_05.outputArrayCount) == 3);
    
    assert(detectRange(readingSorting(&Output_05[0],returnData_05.outputArrayCount),returnData_05.outputArrayCount,DataForDisplay_05)==3);
    
    assert(DataForDisplay_05[0].rangeStart == 0);
    assert(DataForDisplay_05[0].rangeEnd == 3);
    assert(DataForDisplay_05[0].readingsInRange == 4);
    
    assert(DataForDisplay_05[1].rangeStart == 7);
    assert(DataForDisplay_05[1].rangeEnd == 0);
    assert(DataForDisplay_05[1].readingsInRange == 1); 
    
    assert(DataForDisplay_05[2].rangeStart == 10);
    assert(DataForDisplay_05[2].rangeEnd == 0);
    assert(DataForDisplay_05[2].readingsInRange == 1);
    
}
void TEST_CASE_06()
{
    int data_06[7]={10,2024,1800,400,2500,3000,4000};
    int Output_06[7];
    returnData returnData_06;
    returnData_06=DtoA_ConversionArray(&data_06[0],&Output_06[0],7,10);
    assert(returnData_06.value_status==ALL_VALUE_OK);
    assert(returnData_06.outputArrayCount==7);
    
    static rangeInfo DataForDisplay_06[DISPLAY_SIZE];
    assert(DetectAndDisplayRange(&Output_06[0],returnData_06.outputArrayCount) == 3);
    
    assert(detectRange(readingSorting(&Output_06[0],returnData_06.outputArrayCount),returnData_06.outputArrayCount,DataForDisplay_06)==3);
    
    assert(DataForDisplay_06[0].rangeStart == 0);
    assert(DataForDisplay_06[0].rangeEnd == 1);
    assert(DataForDisplay_06[0].readingsInRange == 2);
    
    assert(DataForDisplay_06[1].rangeStart == 4);
    assert(DataForDisplay_06[1].rangeEnd == 7);
    assert(DataForDisplay_06[1].readingsInRange == 4); 
    
    assert(DataForDisplay_06[2].rangeStart == 10);
    assert(DataForDisplay_06[2].rangeEnd == 0);
    assert(DataForDisplay_06[2].readingsInRange == 1);
    
}

int main()
{
   TEST_CASE_01();
   TEST_CASE_02();
   TEST_CASE_03();
   TEST_CASE_04();
   TEST_CASE_05();
   TEST_CASE_06();
}
