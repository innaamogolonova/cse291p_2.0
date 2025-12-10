#include "std_testcase.h"
#include <wchar.h>
static void goodG2B()
{
    int h;
    wchar_t * data;
    data = NULL;
    for(h = 0; h < 1; h++)
    {
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
    }
    printWLine(data);
    free(data);
}
void CWE590_Free_Memory_Not_on_Heap__free_wchar_t_static_17_good()
{
    goodG2B();
}
