#include "std_testcase.h"
#include <wchar.h>
void CWE590_Free_Memory_Not_on_Heap__free_long_alloca_10_bad()
{
    long * data;
    data = NULL;
    if(globalTrue)
    {
        {
            long * dataBuffer = (long *)ALLOCA(100*sizeof(long));
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
