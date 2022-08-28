#include <stdio.h>
#include "D2A_Converter.h"
#include <math.h>


int DtoA_ConversionValue(int CurrntReference,int DigitalInput )
{
	int convertedValue=0;
	float tempConvertedValue;
	tempConvertedValue = ((CurrntReference* DigitalInput)/(pow(2,RESOLUTION) - VALUE_LIMIT));
	convertedValue =(int) round(tempConvertedValue);
	return(convertedValue);
}


returnData DtoA_ConversionArray(int * inputArray,int *outputArray,int Arraysize,int CurrntReference)
{ 
    returnData DACReturn;
    DACReturn.value_status=ALL_VALUE_OK;
	DACReturn.outputArrayCount=0;
	for(int size=0;size<Arraysize;size++)
	{
		if(inputArray[size]<= (pow(2,RESOLUTION) - VALUE_LIMIT))
		{	
		    outputArray[DACReturn.outputArrayCount]=DtoA_ConversionValue(CurrntReference,inputArray[size]);
		    printf("output value=%d\n",outputArray[DACReturn.outputArrayCount]);
			DACReturn.outputArrayCount++;
		}
		else
		{
            DACReturn.value_status=ALL_VALUE_NOTOK;
		}
	}
	return(DACReturn);
}