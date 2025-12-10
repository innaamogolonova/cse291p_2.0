#include "std_testcase.h"
void CWE121_Stack_Based_Buffer_Overflow__CWE805_int_declare_loop_51b_badSink(int * data)
{
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
