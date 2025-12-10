#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_declare_ncpy_13_bad()
{
    wchar_t * data;
    wchar_t dataBadBuffer[10];
    wchar_t dataGoodBuffer[10+1];
    if(GLOBAL_CONST_FIVE==5)
    {
        data = dataBadBuffer;
        data[0] = L'\0';
    }
    {
        wchar_t source[10+1] = SRC_STRING;
        wcsncpy(data, source, wcslen(source) + 1);
        printWLine(data);
    }
}
