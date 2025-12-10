#include "std_testcase.h"
#include <wchar.h>
void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_memcpy_68b_badSink()
{
    wchar_t * data = CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_memcpy_68_badData;
    {
        wchar_t source[10+1] = SRC_STRING;
        memcpy(data, source, (wcslen(source) + 1) * sizeof(wchar_t));
        printWLine(data);
        free(data);
    }
}
