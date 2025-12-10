#include "std_testcase.h"
static void badSink()
{
    int * data = CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_loop_45_badData;
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
void CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_loop_45_bad()
{
    int * data;
    int * dataBadBuffer = (int *)ALLOCA(50*sizeof(int));
    int * dataGoodBuffer = (int *)ALLOCA(100*sizeof(int));
    data = dataBadBuffer;
    CWE121_Stack_Based_Buffer_Overflow__CWE805_int_alloca_loop_45_badData = data;
    badSink();
}
