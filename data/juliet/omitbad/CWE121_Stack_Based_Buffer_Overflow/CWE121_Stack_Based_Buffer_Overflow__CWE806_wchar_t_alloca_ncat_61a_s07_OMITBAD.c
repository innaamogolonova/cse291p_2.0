#include "std_testcase.h"
#include <wchar.h>
wchar_t * CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_alloca_ncat_61b_badSource(wchar_t * data);
void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_alloca_ncat_61_bad()
{
    wchar_t * data;
    wchar_t * dataBuffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    data = dataBuffer;
    data = CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_alloca_ncat_61b_badSource(data);
    {
        wchar_t dest[50] = L"";
        wcsncat(dest, data, wcslen(data));
        dest[50-1] = L'\0';
        printWLine(data);
    }
}
