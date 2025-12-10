#include "std_testcase.h"
#include <wchar.h>
static void goodG2B()
{
    int h;
    char * data;
    char dataBadBuffer[10];
    char dataGoodBuffer[10+1];
    for(h = 0; h < 1; h++)
    {
        data = dataGoodBuffer;
        data[0] = '\0';
    }
    {
        char source[10+1] = SRC_STRING;
        memmove(data, source, (strlen(source) + 1) * sizeof(char));
        printLine(data);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE193_char_declare_memmove_17_good()
{
    goodG2B();
}
