#include "std_testcase.h"
#include <wchar.h>
void CWE590_Free_Memory_Not_on_Heap__free_wchar_t_declare_07_bad()
{
    wchar_t * data;
    data = NULL;
    if(staticFive==5)
    {
        {
            wchar_t dataBuffer[100];
            wmemset(dataBuffer, L'A', 100-1);
            dataBuffer[100-1] = L'\0';
            data = dataBuffer;
        }
    }
    printWLine(data);
    free(data);
}
