#include "std_testcase.h"
#include <wchar.h>
static void goodG2B1()
{
    long * data;
    data = NULL;
    if(globalFalse)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        {
            long * dataBuffer = (long *)malloc(100*sizeof(long));
            if (dataBuffer == NULL)
            {
                printLine("malloc() failed");
                exit(1);
            }
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    dataBuffer[i] = 5L;
                }
            }
            data = dataBuffer;
        }
    }
    printLongLine(data[0]);
    free(data);
}
static void goodG2B2()
{
    long * data;
    data = NULL;
    if(globalTrue)
    {
        {
            long * dataBuffer = (long *)malloc(100*sizeof(long));
            if (dataBuffer == NULL)
            {
                printLine("malloc() failed");
                exit(1);
            }
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    dataBuffer[i] = 5L;
                }
            }
            data = dataBuffer;
        }
    }
    printLongLine(data[0]);
    free(data);
}
void CWE590_Free_Memory_Not_on_Heap__free_long_alloca_10_good()
{
    goodG2B1();
    goodG2B2();
}
