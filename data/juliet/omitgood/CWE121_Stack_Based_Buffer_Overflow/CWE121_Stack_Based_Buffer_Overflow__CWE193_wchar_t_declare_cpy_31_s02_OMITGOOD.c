#include "std_testcase.h"
#include <wchar.h>
static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBadBuffer[10];
    wchar_t dataGoodBuffer[10+1];
    data = dataGoodBuffer;
    data[0] = L'\0';
    {
        wchar_t * dataCopy = data;
        wchar_t * data = dataCopy;
        {
            wchar_t source[10+1] = SRC_STRING;
            wcscpy(data, source);
            printWLine(data);
        }
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_declare_cpy_31_good()
{
    goodG2B();
}
