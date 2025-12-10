#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_memmove_31_bad()
{
    wchar_t * data;
    wchar_t dataBadBuffer[50];
    wchar_t dataGoodBuffer[100];
    data = dataBadBuffer;
    data[0] = L'\0';
    {
        wchar_t * dataCopy = data;
        wchar_t * data = dataCopy;
        {
            wchar_t source[100];
            wmemset(source, L'C', 100-1);
            source[100-1] = L'\0';
            memmove(data, source, 100*sizeof(wchar_t));
            data[100-1] = L'\0';
            printWLine(data);
        }
    }
}
