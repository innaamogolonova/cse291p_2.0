#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE193_char_declare_memmove_17_bad()
{
    int i;
    char * data;
    char dataBadBuffer[10];
    char dataGoodBuffer[10+1];
    for(i = 0; i < 1; i++)
    {
        data = dataBadBuffer;
        data[0] = '\0';
    }
    {
        char source[10+1] = SRC_STRING;
        memmove(data, source, (strlen(source) + 1) * sizeof(char));
        printLine(data);
    }
}
