#include "std_testcase.h"
#include <wchar.h>
static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    while(1)
    {
        wmemset(data, L'A', 50-1);
        data[50-1] = L'\0';
        break;
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
void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_loop_16_good()
{
    goodG2B();
}
