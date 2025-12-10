#include "std_testcase.h"
#include <wchar.h>
wchar_t * CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_ncpy_61b_goodG2BSource(wchar_t * data);
static void goodG2B()
{
    wchar_t * data;
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    data = CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_ncpy_61b_goodG2BSource(data);
    {
        wchar_t dest[50] = L"";
        wcsncpy(dest, data, wcslen(data));
        dest[50-1] = L'\0';
        printWLine(data);
        free(data);
    }
}
void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_ncpy_61_good()
{
    goodG2B();
}
