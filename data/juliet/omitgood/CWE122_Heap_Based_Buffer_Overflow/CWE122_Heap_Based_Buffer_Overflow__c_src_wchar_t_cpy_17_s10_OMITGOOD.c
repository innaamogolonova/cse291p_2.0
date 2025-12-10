#include "std_testcase.h"
#include <wchar.h>
static void goodG2B()
{
    int h;
    wchar_t * data;
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    for(h = 0; h < 1; h++)
    {
        wmemset(data, L'A', 50-1);
        data[50-1] = L'\0';
    }
    {
        wchar_t dest[50] = L"";
        wcscpy(dest, data);
        printWLine(data);
        free(data);
    }
}
void CWE122_Heap_Based_Buffer_Overflow__c_src_wchar_t_cpy_17_good()
{
    goodG2B();
}
