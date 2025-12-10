#include "std_testcase.h"
#include <wchar.h>
void CWE401_Memory_Leak__strdup_wchar_t_17_bad()
{
    int i,j;
    wchar_t * data;
    data = NULL;
    for(i = 0; i < 1; i++)
    {
        {
            wchar_t myString[] = L"myString";
            data = wcsdup(myString);
            printWLine(data);
        }
    }
    for(j = 0; j < 1; j++)
    {
        ;
    }
}
