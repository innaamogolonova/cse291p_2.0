#include "std_testcase.h"
#include <wchar.h>
static void goodG2BSink(wchar_t * data)
{
    {
        wchar_t dest[50] = L"";
        SNPRINTF(dest, wcslen(data), L"%s", data);
        printWLine(data);
    }
}
static void goodG2B()
{
    wchar_t * data;
    void (*funcPtr) (wchar_t *) = goodG2BSink;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    wmemset(data, L'A', 50-1);
    data[50-1] = L'\0';
    funcPtr(data);
}
void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_snprintf_44_good()
{
    goodG2B();
}
