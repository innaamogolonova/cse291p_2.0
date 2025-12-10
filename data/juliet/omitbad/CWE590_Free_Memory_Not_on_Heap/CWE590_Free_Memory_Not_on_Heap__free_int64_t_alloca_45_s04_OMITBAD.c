#include "std_testcase.h"
#include <wchar.h>
static void badSink()
{
    int64_t * data = CWE590_Free_Memory_Not_on_Heap__free_int64_t_alloca_45_badData;
    printLongLongLine(data[0]);
    free(data);
}
void CWE590_Free_Memory_Not_on_Heap__free_int64_t_alloca_45_bad()
{
    int64_t * data;
    data = NULL;
    {
        int64_t * dataBuffer = (int64_t *)ALLOCA(100*sizeof(int64_t));
        {
            size_t i;
            for (i = 0; i < 100; i++)
            {
                dataBuffer[i] = 5LL;
            }
        }
        data = dataBuffer;
    }
    CWE590_Free_Memory_Not_on_Heap__free_int64_t_alloca_45_badData = data;
    badSink();
}
