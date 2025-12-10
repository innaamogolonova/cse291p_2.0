#include "std_testcase.h"
void CWE122_Heap_Based_Buffer_Overflow__CWE131_loop_10_bad()
{
    int * data;
    data = NULL;
    if(globalTrue)
    {
        data = (int *)malloc(10);
        if (data == NULL) {exit(-1);}
    }
    {
        int source[10] = {0};
        size_t i;
        for (i = 0; i < 10; i++)
        {
            data[i] = source[i];
        }
        printIntLine(data[0]);
        free(data);
    }
}
