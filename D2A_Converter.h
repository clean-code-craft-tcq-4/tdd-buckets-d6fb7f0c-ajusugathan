
#define RESOLUTION    12
#define VALUE_LIMIT   2
#define ALL_VALUE_OK   0
#define ALL_VALUE_NOTOK   1

typedef struct{
    int value_status;
    int outputArrayCount;
}returnData;

int DtoA_ConversionValue(int CurrntReference,int DigitalInput );
returnData DtoA_ConversionArray(int * inputArray,int *outputArray,int Arraysize,int CurrntReference);