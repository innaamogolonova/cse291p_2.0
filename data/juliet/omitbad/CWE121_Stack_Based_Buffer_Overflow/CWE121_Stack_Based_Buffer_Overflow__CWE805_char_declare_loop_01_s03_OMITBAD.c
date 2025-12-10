#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_loop_01_bad()
{
    char * data;
    char dataBadBuffer[50];
    char dataGoodBuffer[100];
    data = dataBadBuffer;
    data[0] = '\0';
    {
        size_t i;
        char source[100];
        memset(source, 'C', 100-1);
        source[100-1] = '\0';
        for (i = 0; i < 100; i++)
        {
            data[i] = source[i];
        }
        data[100-1] = '\0';
        printLine(data);
    }
}
