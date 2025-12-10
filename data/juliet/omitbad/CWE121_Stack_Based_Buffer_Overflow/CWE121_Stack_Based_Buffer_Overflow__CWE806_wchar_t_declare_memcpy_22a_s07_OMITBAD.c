#include "std_testcase.h"
#include <wchar.h>
int CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memcpy_22_badGlobal = 0;
wchar_t * CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memcpy_22_badSource(wchar_t * data);
void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memcpy_22_bad()
{
    wchar_t * data;
    wchar_t dataBuffer[100];
    data = dataBuffer;
    CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memcpy_22_badGlobal = 1;
    data = CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_declare_memcpy_22_badSource(data);
    {
        wchar_t dest[50] = L"";
        memcpy(dest, data, wcslen(data)*sizeof(wchar_t));
        dest[50-1] = L'\0';
        printWLine(data);
    }
}
