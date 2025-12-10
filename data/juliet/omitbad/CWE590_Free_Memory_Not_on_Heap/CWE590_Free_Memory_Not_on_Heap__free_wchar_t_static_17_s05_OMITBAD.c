#include "std_testcase.h"
#include <wchar.h>
void CWE590_Free_Memory_Not_on_Heap__free_wchar_t_static_17_bad()
{
    int i;
    wchar_t * data;
    data = NULL;
    for(i = 0; i < 1; i++)
    {
        {
            static wchar_t dataBuffer[100];
            wmemset(dataBuffer, L'A', 100-1);
            dataBuffer[100-1] = L'\0';
            data = dataBuffer;
        }
    }
    printWLine(data);
    free(data);
}
