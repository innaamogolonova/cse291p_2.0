#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__src_char_declare_cpy_03_bad()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    if(5==5)
    {
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
    }
    {
        char dest[50] = "";
        strcpy(dest, data);
        printLine(data);
    }
}
