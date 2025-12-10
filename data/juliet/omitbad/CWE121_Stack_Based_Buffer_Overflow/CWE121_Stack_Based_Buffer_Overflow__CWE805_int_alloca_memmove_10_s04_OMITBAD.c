#include "std_testcase.h"
void CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_memmove_10_bad()
{
    int * data;
    int * dataBadBuffer = (int *)ALLOCA(50*sizeof(int));
    int * dataGoodBuffer = (int *)ALLOCA(100*sizeof(int));
    if(globalTrue)
    {
        data = dataBadBuffer;
    }
    {
        int source[100] = {0};
        memmove(data, source, 100*sizeof(int));
        printIntLine(data[0]);
    }
}
