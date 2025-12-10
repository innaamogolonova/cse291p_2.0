#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_alloca_memmove_17_bad()
{
    int i;
    wchar_t * data;
    wchar_t * dataBuffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    data = dataBuffer;
    for(i = 0; i < 1; i++)
    {
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
    }
    {
        wchar_t dest[50] = L"";
        memmove(dest, data, wcslen(data)*sizeof(wchar_t));
        dest[50-1] = L'\0';
        printWLine(data);
    }
}
