#include "std_testcase.h"
#include <wchar.h>
static void goodG2B()
{
    wchar_t * data;
    wchar_t * dataBuffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    data = dataBuffer;
    goto source;
source:
    wmemset(data, L'A', 50-1);
    data[50-1] = L'\0';
    {
        wchar_t dest[50] = L"";
        wcsncpy(dest, data, wcslen(data));
        dest[50-1] = L'\0';
        printWLine(data);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_alloca_ncpy_18_good()
{
    goodG2B();
}
