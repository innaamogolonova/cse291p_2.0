#include "std_testcase.h"
#include <wchar.h>
char * CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_loop_61b_badSource(char * data);
void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_loop_61_bad()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    data = CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_loop_61b_badSource(data);
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
