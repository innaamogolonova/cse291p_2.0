#include "std_testcase.h"
#include <wchar.h>
static void goodG2B()
{
    wchar_t * data;
    wchar_t * *dataPtr1 = &data;
    wchar_t * *dataPtr2 = &data;
    data = NULL;
    {
        wchar_t * data = *dataPtr1;
        {
            wchar_t * dataBuffer = (wchar_t *)malloc(100*sizeof(wchar_t));
            if (dataBuffer == NULL)
            {
                printLine("malloc() failed");
                exit(1);
            }
            wmemset(dataBuffer, L'A', 100-1);
            dataBuffer[100-1] = L'\0';
            data = dataBuffer;
        }
        *dataPtr1 = data;
    }
    {
        wchar_t * data = *dataPtr2;
        printWLine(data);
        free(data);
    }
}
void CWE590_Free_Memory_Not_on_Heap__free_wchar_t_alloca_32_good()
{
    goodG2B();
}
