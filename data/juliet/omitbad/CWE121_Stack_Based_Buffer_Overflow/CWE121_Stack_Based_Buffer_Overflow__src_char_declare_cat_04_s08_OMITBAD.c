#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__src_char_declare_cat_04_bad()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    if(STATIC_CONST_TRUE)
    {
        memset(data, 'A', 100-1);
        data[100-1] = '\0';
    }
    {
        char dest[50] = "";
        strcat(dest, data);
        printLine(data);
    }
}
