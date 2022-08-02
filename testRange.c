#include <stdio.h>
#include <assert.h>
#include "detectRange.h"

void TEST_CASE_01()
{
    int data[2]={4,5};
	  int totalreadings=sizeof(data)/sizeof(data[0]);
    assert(DetectAndDisplayRange(data,totalreadings) == 1);
}

int main()
{
   TEST_CASE_01();
}
