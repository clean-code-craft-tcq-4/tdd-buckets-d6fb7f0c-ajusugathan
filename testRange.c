#include <stdio.h>
#include <assert.h>
#include "detectRange.h"

void TEST_CASE_01()
{
    int data[2]={4,5};
    int totalreadings=sizeof(data)/sizeof(data[0]);
    assert(DetectAndDisplayRange(data,totalreadings) == 1);
}
void TEST_CASE_02()
{
    int data[5]={4,4,5,8,10};
    int totalreadings=sizeof(data)/sizeof(data[0]);
    assert(DetectAndDisplayRange(data,totalreadings) == 3);
}
int main()
{
   TEST_CASE_01();
   TEST_CASE_01();
}
