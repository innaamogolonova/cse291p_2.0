#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_alloca_cpy_04_bad()
{
    wchar_t * data;
    wchar_t * dataBadBuffer = (wchar_t *)ALLOCA((10)*sizeof(wchar_t));
    wchar_t * dataGoodBuffer = (wchar_t *)ALLOCA((10+1)*sizeof(wchar_t));
    if(STATIC_CONST_TRUE)
    {
        data = dataBadBuffer;
        data[0] = L'\0';
    }
    {
        wchar_t source[10+1] = SRC_STRING;
        wcscpy(data, source);
        printWLine(data);
    }
}
