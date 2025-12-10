#include "std_testcase.h"
void CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_52b_badSink(int * data);
void CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_52_bad()
{
    int * data;
    data = NULL;
    data = (int *)malloc(10);
    if (data == NULL) {exit(-1);}
    CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_52b_badSink(data);
}
