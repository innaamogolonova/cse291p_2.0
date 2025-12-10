#include "std_testcase.h"
#include <wchar.h>
static void good1()
{
    if(GLOBAL_CONST_FIVE!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        {
            wchar_t * data = (wchar_t *)malloc(100*sizeof(wchar_t));
            if (data == NULL) {exit(-1);}
            wchar_t * tmpData;
            wcscpy(data, L"A String");
            printWLine(data);
            tmpData = (wchar_t *)realloc(data, (130000)*sizeof(wchar_t));
            if (tmpData != NULL)
            {
                data = tmpData;
                wcscpy(data, L"New String");
                printWLine(data);
            }
            free(data);
        }
    }
}
static void good2()
{
    if(GLOBAL_CONST_FIVE==5)
    {
        {
            wchar_t * data = (wchar_t *)malloc(100*sizeof(wchar_t));
            if (data == NULL) {exit(-1);}
            wchar_t * tmpData;
            wcscpy(data, L"A String");
            printWLine(data);
            tmpData = (wchar_t *)realloc(data, (130000)*sizeof(wchar_t));
            if (tmpData != NULL)
            {
                data = tmpData;
                wcscpy(data, L"New String");
                printWLine(data);
            }
            free(data);
        }
    }
}
void CWE401_Memory_Leak__malloc_realloc_wchar_t_13_good()
{
    good1();
    good2();
}
