#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_declare_ncpy_51b_badSink(char * data)
{
    {
        char dest[50] = "";
        strncpy(dest, data, strlen(data));
        dest[50-1] = '\0';
        printLine(data);
    }
}
