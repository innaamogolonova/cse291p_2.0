#include "std_testcase.h"
static void goodG2B()
{
    int * data;
    int * *dataPtr1 = &data;
    int * *dataPtr2 = &data;
    data = NULL;
    {
        int * data = *dataPtr1;
        data = (int *)ALLOCA(10*sizeof(int));
        *dataPtr1 = data;
    }
    {
        int * data = *dataPtr2;
        {
            int source[10] = {0};
            size_t i;
            for (i = 0; i < 10; i++)
            {
                data[i] = source[i];
            }
            printIntLine(data[0]);
        }
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE131_loop_32_good()
{
    goodG2B();
}
