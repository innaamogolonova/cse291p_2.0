#include "std_testcase.h"
#include <wchar.h>
void CWE590_Free_Memory_Not_on_Heap__free_int_declare_02_bad()
{
    int * data;
    data = NULL;
    if(1)
    {
        {
            int dataBuffer[100];
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
