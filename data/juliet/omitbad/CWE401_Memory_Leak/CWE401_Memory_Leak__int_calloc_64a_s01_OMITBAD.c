#include "std_testcase.h"
#include <wchar.h>
void CWE401_Memory_Leak__int_calloc_64b_badSink(void * dataVoidPtr);
void CWE401_Memory_Leak__int_calloc_64_bad()
{
    int * data;
    data = NULL;
    data = (int *)calloc(100, sizeof(int));
    if (data == NULL) {exit(-1);}
    data[0] = 5;
    printIntLine(data[0]);
    CWE401_Memory_Leak__int_calloc_64b_badSink(&data);
}
