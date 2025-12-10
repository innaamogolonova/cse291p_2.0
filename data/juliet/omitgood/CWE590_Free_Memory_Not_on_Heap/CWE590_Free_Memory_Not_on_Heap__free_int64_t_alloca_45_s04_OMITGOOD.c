#include "std_testcase.h"
#include <wchar.h>
static void goodG2BSink()
{
    int64_t * data = CWE590_Free_Memory_Not_on_Heap__free_int64_t_alloca_45_goodG2BData;
    printLongLongLine(data[0]);
    free(data);
}
static void goodG2B()
{
    int64_t * data;
    data = NULL;
    {
        int64_t * dataBuffer = (int64_t *)malloc(100*sizeof(int64_t));
        if (dataBuffer == NULL)
        {
            printLine("malloc() failed");
            exit(1);
        }
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                dataBuffer[i] = 5LL;
            }
        }
        data = dataBuffer;
    }
    CWE590_Free_Memory_Not_on_Heap__free_int64_t_alloca_45_goodG2BData = data;
    goodG2BSink();
}
void CWE590_Free_Memory_Not_on_Heap__free_int64_t_alloca_45_good()
{
    goodG2B();
}
