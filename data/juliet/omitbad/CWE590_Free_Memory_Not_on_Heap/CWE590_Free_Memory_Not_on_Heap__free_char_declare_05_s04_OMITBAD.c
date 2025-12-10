#include "std_testcase.h"
#include <wchar.h>
void CWE590_Free_Memory_Not_on_Heap__free_char_declare_05_bad()
{
    char * data;
    data = NULL;
    if(staticTrue)
    {
        {
            char dataBuffer[100];
            memset(dataBuffer, 'A', 100-1);
            dataBuffer[100-1] = '\0';
            data = dataBuffer;
        }
    }
    printLine(data);
    free(data);
}
