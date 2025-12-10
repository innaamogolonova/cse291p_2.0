#include "std_testcase.h"
#include <wchar.h>
static void goodG2B()
{
    wchar_t * data;
    wchar_t * *dataPtr1 = &data;
    wchar_t * *dataPtr2 = &data;
    wchar_t dataBadBuffer[50];
    wchar_t dataGoodBuffer[100];
    {
        wchar_t * data = *dataPtr1;
        data = dataGoodBuffer;
        data[0] = L'\0';
        *dataPtr1 = data;
    }
    {
        wchar_t * data = *dataPtr2;
        {
            wchar_t source[100];
            wmemset(source, L'C', 100-1);
            source[100-1] = L'\0';
            wcscpy(data, source);
            printWLine(data);
        }
    }
}
void CWE121_Stack_Based_Buffer_Overflow__dest_wchar_t_declare_cpy_32_good()
{
    goodG2B();
}
