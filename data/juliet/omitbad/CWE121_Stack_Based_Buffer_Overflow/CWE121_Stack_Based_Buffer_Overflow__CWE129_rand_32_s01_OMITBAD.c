#include "std_testcase.h"
void CWE121_Stack_Based_Buffer_Overflow__CWE129_rand_32_bad()
{
    int data;
    int *dataPtr1 = &data;
    int *dataPtr2 = &data;
    data = -1;
    {
        int data = *dataPtr1;
        data = RAND32();
        *dataPtr1 = data;
    }
    {
        int data = *dataPtr2;
        {
            int i;
            int buffer[10] = { 0 };
            if (data >= 0)
            {
                buffer[data] = 1;
                for(i = 0; i < 10; i++)
                {
                    printIntLine(buffer[i]);
                }
            }
            else
            {
                printLine("ERROR: Array index is negative.");
            }
        }
    }
}
