#include "std_testcase.h"
#include <wchar.h>
char * CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_memcpy_61b_badSource(char * data);
void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_memcpy_61_bad()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    data = CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_memcpy_61b_badSource(data);
    {
        char dest[50] = "";
        memcpy(dest, data, strlen(data)*sizeof(char));
        dest[50-1] = '\0';
        printLine(data);
    }
}
