#include "std_testcase.h"
static void goodG2B1()
{
    int64_t * data;
    data = NULL;
    if(0)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = (int64_t *)malloc(sizeof(*data));
        if (data == NULL) {exit(-1);}
        *data = 2147483643LL;
    }
    printLongLongLine(*data);
    free(data);
}
static void goodG2B2()
{
    int64_t * data;
    data = NULL;
    if(1)
    {
        data = (int64_t *)malloc(sizeof(*data));
        if (data == NULL) {exit(-1);}
        *data = 2147483643LL;
    }
    printLongLongLine(*data);
    free(data);
}
void CWE122_Heap_Based_Buffer_Overflow__sizeof_int64_t_02_good()
{
    goodG2B1();
    goodG2B2();
}
