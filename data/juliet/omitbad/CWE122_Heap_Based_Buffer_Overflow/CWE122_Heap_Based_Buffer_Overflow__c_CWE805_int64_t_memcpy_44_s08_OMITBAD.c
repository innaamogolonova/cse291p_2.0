#include "std_testcase.h"
static void badSink(int64_t * data)
{
    {
        int64_t source[100] = {0};
        memcpy(data, source, 100*sizeof(int64_t));
        printLongLongLine(data[0]);
        free(data);
    }
}
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int64_t_memcpy_44_bad()
{
    int64_t * data;
    void (*funcPtr) (int64_t *) = badSink;
    data = NULL;
    data = (int64_t *)malloc(50*sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    funcPtr(data);
}
