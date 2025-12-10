#include "std_testcase.h"
#include <wchar.h>
static void goodB2G()
{
    int i,k;
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
    for(k = 0; k < 1; k++)
    {
        free(data);
    }
}
static void goodG2B()
{
    int h,j;
    wchar_t * data;
    data = NULL;
    for(h = 0; h < 1; h++)
    {
        data = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
        wcscpy(data, L"a string");
        printWLine(data);
    }
    for(j = 0; j < 1; j++)
    {
        ;
    }
}
void CWE401_Memory_Leak__strdup_wchar_t_17_good()
{
    goodB2G();
    goodG2B();
}
