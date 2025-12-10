#include "std_testcase.h"
#include <wchar.h>
static void goodG2B1()
{
    int * data;
    data = NULL;
    if(0)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        {
            int * dataBuffer = (int *)malloc(100*sizeof(int));
            if (dataBuffer == NULL)
            {
                printLine("malloc() failed");
                exit(1);
            }
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    dataBuffer[i] = 5;
                }
            }
            data = dataBuffer;
        }
    }
    printIntLine(data[0]);
    free(data);
}
static void goodG2B2()
{
    int * data;
    data = NULL;
    if(1)
    {
        {
            int * dataBuffer = (int *)malloc(100*sizeof(int));
            if (dataBuffer == NULL)
            {
                printLine("malloc() failed");
                exit(1);
            }
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    dataBuffer[i] = 5;
                }
            }
            data = dataBuffer;
        }
    }
    printIntLine(data[0]);
    free(data);
}
void CWE590_Free_Memory_Not_on_Heap__free_int_declare_02_good()
{
    goodG2B1();
    goodG2B2();
}
