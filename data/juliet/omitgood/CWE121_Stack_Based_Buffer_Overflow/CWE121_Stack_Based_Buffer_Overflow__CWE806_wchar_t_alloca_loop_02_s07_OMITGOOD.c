#include "std_testcase.h"
#include <wchar.h>
static void goodG2B1()
{
    wchar_t * data;
    wchar_t * dataBuffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    data = dataBuffer;
    if(0)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        wmemset(data, L'A', 50-1);
        data[50-1] = L'\0';
    }
    {
        wchar_t dest[50] = L"";
        size_t i, dataLen;
        dataLen = wcslen(data);
        for (i = 0; i < dataLen; i++)
        {
            dest[i] = data[i];
        }
        dest[50-1] = L'\0';
        printWLine(data);
    }
}
static void goodG2B2()
{
    wchar_t * data;
    wchar_t * dataBuffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    data = dataBuffer;
    if(1)
    {
        wmemset(data, L'A', 50-1);
        data[50-1] = L'\0';
    }
    {
        wchar_t dest[50] = L"";
        size_t i, dataLen;
        dataLen = wcslen(data);
        for (i = 0; i < dataLen; i++)
        {
            dest[i] = data[i];
        }
        dest[50-1] = L'\0';
        printWLine(data);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_alloca_loop_02_good()
{
    goodG2B1();
    goodG2B2();
}
