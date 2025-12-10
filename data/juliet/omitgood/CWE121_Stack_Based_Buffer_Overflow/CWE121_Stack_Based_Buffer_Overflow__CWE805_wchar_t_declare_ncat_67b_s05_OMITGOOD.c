#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_ncat_67b_goodG2BSink(CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_ncat_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1);
        source[100-1] = L'\0';
        wcsncat(data, source, 100);
        printWLine(data);
    }
}
