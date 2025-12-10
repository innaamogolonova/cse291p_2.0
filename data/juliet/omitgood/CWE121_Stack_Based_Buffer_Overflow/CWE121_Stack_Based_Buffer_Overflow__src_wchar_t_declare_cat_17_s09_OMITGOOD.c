#include "std_testcase.h"
#include <wchar.h>
static void goodG2B()
{
    int h;
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    for(h = 0; h < 1; h++)
    {
        wmemset(data, L'A', 50-1);
        data[50-1] = L'\0';
    }
    {
        wchar_t dest[50] = L"";
        wcscat(dest, data);
        printWLine(data);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_17_good()
{
    goodG2B();
}
