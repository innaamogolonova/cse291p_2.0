#include "std_testcase.h"
#include <wchar.h>
void CWE401_Memory_Leak__malloc_realloc_wchar_t_13_bad()
{
    if(GLOBAL_CONST_FIVE==5)
    {
        {
            wchar_t * data = (wchar_t *)malloc(100*sizeof(wchar_t));
            if (data == NULL) {exit(-1);}
            wcscpy(data, L"A String");
            printWLine(data);
            data = (wchar_t *)realloc(data, (130000)*sizeof(wchar_t));
            if (data != NULL)
            {
                wcscpy(data, L"New String");
                printWLine(data);
                free(data);
            }
        }
    }
}
