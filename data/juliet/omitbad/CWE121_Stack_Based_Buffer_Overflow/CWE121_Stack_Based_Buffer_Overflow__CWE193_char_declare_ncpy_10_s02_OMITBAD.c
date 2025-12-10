#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE193_char_declare_ncpy_10_bad()
{
    char * data;
    char dataBadBuffer[10];
    char dataGoodBuffer[10+1];
    if(globalTrue)
    {
        data = dataBadBuffer;
        data[0] = '\0';
    }
    {
        char source[10+1] = SRC_STRING;
        strncpy(data, source, strlen(source) + 1);
        printLine(data);
    }
}
