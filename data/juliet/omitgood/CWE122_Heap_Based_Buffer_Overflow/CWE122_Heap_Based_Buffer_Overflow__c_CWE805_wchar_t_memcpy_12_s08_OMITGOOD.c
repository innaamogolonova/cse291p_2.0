#include "std_testcase.h"
#include <wchar.h>
static void goodG2B()
{
    wchar_t * data;
    data = NULL;
    if(globalReturnsTrueOrFalse())
    {
        data = (wchar_t *)malloc(100*sizeof(wchar_t));
        if (data == NULL) {exit(-1);}
        data[0] = L'\0';
    }
    else
    {
        data = (wchar_t *)malloc(100*sizeof(wchar_t));
        if (data == NULL) {exit(-1);}
        data[0] = L'\0';
    }
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1);
        source[100-1] = L'\0';
        memcpy(data, source, 100*sizeof(wchar_t));
        data[100-1] = L'\0';
        printWLine(data);
        free(data);
    }
}
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_memcpy_12_good()
{
    goodG2B();
}
