#include "std_testcase.h"
static twoIntsStruct * badSource(twoIntsStruct * data)
{
    data = (twoIntsStruct *)malloc(sizeof(data));
    if (data == NULL) {exit(-1);}
    data->intOne = 1;
    data->intTwo = 2;
    return data;
}
void CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_42_bad()
{
    twoIntsStruct * data;
    data = NULL;
    data = badSource(data);
    printStructLine(data);
    free(data);
}
