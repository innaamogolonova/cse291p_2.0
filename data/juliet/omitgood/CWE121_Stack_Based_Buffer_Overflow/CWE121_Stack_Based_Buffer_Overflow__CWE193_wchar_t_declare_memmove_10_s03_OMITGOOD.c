#include "std_testcase.h"
#include <wchar.h>
static void goodG2B1()
{
    wchar_t * data;
    wchar_t dataBadBuffer[10];
    wchar_t dataGoodBuffer[10+1];
    if(globalFalse)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = dataGoodBuffer;
        data[0] = L'\0';
    }
    {
        wchar_t source[10+1] = SRC_STRING;
        memmove(data, source, (wcslen(source) + 1) * sizeof(wchar_t));
        printWLine(data);
    }
}
static void goodG2B2()
{
    wchar_t * data;
    wchar_t dataBadBuffer[10];
    wchar_t dataGoodBuffer[10+1];
    if(globalTrue)
    {
        data = dataGoodBuffer;
        data[0] = L'\0';
    }
    {
        wchar_t source[10+1] = SRC_STRING;
        memmove(data, source, (wcslen(source) + 1) * sizeof(wchar_t));
        printWLine(data);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_declare_memmove_10_good()
{
    goodG2B1();
    goodG2B2();
}
