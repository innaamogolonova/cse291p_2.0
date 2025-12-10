#include "std_testcase.h"
#include <wchar.h>
static void badSink(wchar_t * data)
{
    {
        wchar_t dest[50] = L"";
        SNPRINTF(dest, wcslen(data), L"%s", data);
        printWLine(data);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_snprintf_44_bad()
{
    wchar_t * data;
    void (*funcPtr) (wchar_t *) = badSink;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    wmemset(data, L'A', 100-1);
    data[100-1] = L'\0';
    funcPtr(data);
}
