#include "std_testcase.h"
#include <wchar.h>
int CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memcpy_22_goodG2B1Global = 0;
int CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memcpy_22_goodG2B2Global = 0;
wchar_t * CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memcpy_22_goodG2B1Source(wchar_t * data);
static void goodG2B1()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memcpy_22_goodG2B1Global = 0;
    data = CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memcpy_22_goodG2B1Source(data);
    {
        wchar_t dest[50] = L"";
        memcpy(dest, data, wcslen(data)*sizeof(wchar_t));
        dest[50-1] = L'\0';
        printWLine(data);
    }
}
wchar_t * CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memcpy_22_goodG2B2Source(wchar_t * data);
static void goodG2B2()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memcpy_22_goodG2B2Global = 1;
    data = CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memcpy_22_goodG2B2Source(data);
    {
        wchar_t dest[50] = L"";
        memcpy(dest, data, wcslen(data)*sizeof(wchar_t));
        dest[50-1] = L'\0';
        printWLine(data);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memcpy_22_good()
{
    goodG2B1();
    goodG2B2();
}
