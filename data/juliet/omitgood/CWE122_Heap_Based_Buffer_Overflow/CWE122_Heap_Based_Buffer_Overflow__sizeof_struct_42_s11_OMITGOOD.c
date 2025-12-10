#include "std_testcase.h"
static twoIntsStruct * goodG2BSource(twoIntsStruct * data)
{
    data = (twoIntsStruct *)malloc(sizeof(*data));
    if (data == NULL) {exit(-1);}
    data->intOne = 1;
    data->intTwo = 2;
    return data;
}
static void goodG2B()
{
    twoIntsStruct * data;
    data = NULL;
    data = goodG2BSource(data);
    printStructLine(data);
    free(data);
}
void CWE122_Heap_Based_Buffer_Overflow__sizeof_struct_42_good()
{
    goodG2B();
}
