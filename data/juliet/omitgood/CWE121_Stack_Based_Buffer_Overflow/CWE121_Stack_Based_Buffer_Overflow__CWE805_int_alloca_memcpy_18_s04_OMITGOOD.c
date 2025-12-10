#include "std_testcase.h"
static void goodG2B()
{
    int * data;
    int * dataBadBuffer = (int *)ALLOCA(50*sizeof(int));
    int * dataGoodBuffer = (int *)ALLOCA(100*sizeof(int));
    goto source;
source:
    data = dataGoodBuffer;
    {
        int source[100] = {0};
        memcpy(data, source, 100*sizeof(int));
        printIntLine(data[0]);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memcpy_18_good()
{
    goodG2B();
}
