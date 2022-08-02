
typedef struct
{
int rangeStart;
int rangeEnd;
int readingsInRange;
}rangeInfo;

int detectRange(int * reading,int size,rangeInfo *Data_struct);
void printRangeInfo(rangeInfo *Data_struct,int totalRange);
