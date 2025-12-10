#include "std_testcase.h"
#include <wchar.h>
void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_memmove_15_bad()
{
    wchar_t * data;
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    switch(6)
    {
    case 6:
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
        break;
    default:
        printLine("Benign, fixed string");
        break;
    }
    {
        wchar_t dest[50] = L"";
        memmove(dest, data, wcslen(data)*sizeof(wchar_t));
        dest[50-1] = L'\0';
        printWLine(data);
        free(data);
    }
}
