#include "std_testcase.h"
#include <wchar.h>
static void goodG2B1()
{
    wchar_t * data;
    wchar_t dataBadBuffer[50];
    wchar_t dataGoodBuffer[100];
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
        wchar_t source[100];
        wmemset(source, L'C', 100-1);
        source[100-1] = L'\0';
        SNPRINTF(data, 100, L"%s", source);
        printWLine(data);
    }
}
static void goodG2B2()
{
    wchar_t * data;
    wchar_t dataBadBuffer[50];
    wchar_t dataGoodBuffer[100];
    if(globalTrue)
    {
        data = dataGoodBuffer;
        data[0] = L'\0';
    }
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1);
        source[100-1] = L'\0';
        SNPRINTF(data, 100, L"%s", source);
        printWLine(data);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_snprintf_10_good()
{
    goodG2B1();
    goodG2B2();
}
