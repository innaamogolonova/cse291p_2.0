#include "std_testcase.h"
static void goodG2BSink()
{
    int * data = CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_loop_45_goodG2BData;
    {
        int source[100] = {0};
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                data[i] = source[i];
            }
            printIntLine(data[0]);
        }
    }
}
static void goodG2B()
{
    int * data;
    int * dataBadBuffer = (int *)ALLOCA(50*sizeof(int));
    int * dataGoodBuffer = (int *)ALLOCA(100*sizeof(int));
    data = dataGoodBuffer;
    CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_loop_45_goodG2BData = data;
    goodG2BSink();
}
void CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_loop_45_good()
{
    goodG2B();
}
