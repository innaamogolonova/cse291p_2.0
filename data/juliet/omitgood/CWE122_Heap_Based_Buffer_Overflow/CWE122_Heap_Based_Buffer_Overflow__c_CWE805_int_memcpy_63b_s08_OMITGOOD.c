#include "std_testcase.h"
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memcpy_63b_goodG2BSink(int * * dataPtr)
{
    int * data = *dataPtr;
    {
        int source[100] = {0};
        memcpy(data, source, 100*sizeof(int));
        printIntLine(data[0]);
        free(data);
    }
}
