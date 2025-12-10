#include "std_testcase.h"
static void goodG2B1()
{
    int * data;
    int * dataBadBuffer = (int *)ALLOCA(50*sizeof(int));
    int * dataGoodBuffer = (int *)ALLOCA(100*sizeof(int));
    if(globalFalse)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = dataGoodBuffer;
    }
    {
        int source[100] = {0};
        memmove(data, source, 100*sizeof(int));
        printIntLine(data[0]);
    }
}
static void goodG2B2()
{
    int * data;
    int * dataBadBuffer = (int *)ALLOCA(50*sizeof(int));
    int * dataGoodBuffer = (int *)ALLOCA(100*sizeof(int));
    if(globalTrue)
    {
        data = dataGoodBuffer;
    }
    {
        int source[100] = {0};
        memmove(data, source, 100*sizeof(int));
        printIntLine(data[0]);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memmove_10_good()
{
    goodG2B1();
    goodG2B2();
}
