#include "std_testcase.h"
void CWE121_Stack_Based_Buffer_Overflow__CWE131_memcpy_11_bad()
{
    int * data;
    data = NULL;
    if(globalReturnsTrue())
    {
        data = (int *)ALLOCA(10);
    }
    {
        int source[10] = {0};
        memcpy(data, source, 10*sizeof(int));
        printIntLine(data[0]);
    }
}
