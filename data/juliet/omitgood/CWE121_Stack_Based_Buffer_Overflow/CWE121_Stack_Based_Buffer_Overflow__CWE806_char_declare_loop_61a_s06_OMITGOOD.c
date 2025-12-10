#include "std_testcase.h"
#include <wchar.h>
char * CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_loop_61b_goodG2BSource(char * data);
static void goodG2B()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    data = CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_loop_61b_goodG2BSource(data);
    {
        char dest[50] = "";
        size_t i, dataLen;
        dataLen = strlen(data);
        for (i = 0; i < dataLen; i++)
        {
            dest[i] = data[i];
        }
        dest[50-1] = '\0';
        printLine(data);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_loop_61_good()
{
    goodG2B();
}
