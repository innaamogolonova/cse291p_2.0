#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_declare_cat_17_bad()
{
    int i;
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    for(i = 0; i < 1; i++)
    {
        wmemset(data, L'A', 100-1);
        data[100-1] = L'\0';
    }
    {
        wchar_t dest[50] = L"";
        wcscat(dest, data);
        printWLine(data);
    }
}
