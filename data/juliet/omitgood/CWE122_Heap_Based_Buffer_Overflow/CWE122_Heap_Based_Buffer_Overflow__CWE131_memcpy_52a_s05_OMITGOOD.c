#include "std_testcase.h"
void CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_52b_goodG2BSink(int * data);
static void goodG2B()
{
    int * data;
    data = NULL;
    data = (int *)malloc(10*sizeof(int));
    if (data == NULL) {exit(-1);}
    CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_52b_goodG2BSink(data);
}
void CWE122_Heap_Based_Buffer_Overflow__CWE131_memcpy_52_good()
{
    goodG2B();
}
