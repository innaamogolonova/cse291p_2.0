#include "std_testcase.h"
#include <wchar.h>
void CWE590_Free_Memory_Not_on_Heap__free_int64_t_static_07_bad()
{
    int64_t * data;
    data = NULL;
    if(staticFive==5)
    {
        {
            static int64_t dataBuffer[100];
            {
                size_t i;
                for (i = 0; i < 100; i++)
                {
                    dataBuffer[i] = 5LL;
                }
            }
            data = dataBuffer;
        }
    }
    printLongLongLine(data[0]);
    free(data);
}
