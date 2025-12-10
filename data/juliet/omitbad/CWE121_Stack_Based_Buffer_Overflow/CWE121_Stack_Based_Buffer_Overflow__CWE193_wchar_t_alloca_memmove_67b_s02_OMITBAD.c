#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_alloca_memmove_67b_badSink(CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_alloca_memmove_67_structType myStruct)
{
    wchar_t * data = myStruct.structFirst;
    {
        wchar_t source[10+1] = SRC_STRING;
        memmove(data, source, (wcslen(source) + 1) * sizeof(wchar_t));
        printWLine(data);
    }
}
