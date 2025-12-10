#include "std_testcase.h"
#include <wchar.h>
wchar_t * CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_ncpy_61b_badSource(wchar_t * data);
void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_ncpy_61_bad()
{
    wchar_t * data;
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    data = CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_ncpy_61b_badSource(data);
    {
        wchar_t dest[50] = L"";
        wcsncpy(dest, data, wcslen(data));
        dest[50-1] = L'\0';
        printWLine(data);
        free(data);
    }
}
