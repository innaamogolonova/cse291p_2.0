#include "std_testcase.h"
void CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_02_bad()
{
    int64_t * data;
    data = NULL;
    if(1)
    {
        data = (int64_t *)malloc(sizeof(data));
        if (data == NULL) {exit(-1);}
        *data = 2147483643LL;
    }
    printLongLongLine(*data);
    free(data);
}
