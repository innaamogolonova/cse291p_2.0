#include "std_testcase.h"
static void goodG2B1()
{
    int * data;
    data = NULL;
    if(globalReturnsFalse())
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = (int *)ALLOCA(10*sizeof(int));
    }
    {
        int source[10] = {0};
        memcpy(data, source, 10*sizeof(int));
        printIntLine(data[0]);
    }
}
static void goodG2B2()
{
    int * data;
    data = NULL;
    if(globalReturnsTrue())
    {
        data = (int *)ALLOCA(10*sizeof(int));
    }
    {
        int source[10] = {0};
        memcpy(data, source, 10*sizeof(int));
        printIntLine(data[0]);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE131_memcpy_11_good()
{
    goodG2B1();
    goodG2B2();
}
