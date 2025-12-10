#include "std_testcase.h"
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memmove_18_bad()
{
    int64_t * data;
    data = NULL;
    goto source;
source:
    data = (int64_t *)malloc(50*sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    {
        int64_t source[100] = {0};
        memmove(data, source, 100*sizeof(int64_t));
        printLongLongLine(data[0]);
        free(data);
    }
}
