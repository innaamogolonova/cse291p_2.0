#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE805_char_alloca_ncpy_54e_goodG2BSink(char * data)
{
    {
        char source[100];
        memset(source, 'C', 100-1);
        source[100-1] = '\0';
        strncpy(data, source, 100-1);
        data[100-1] = '\0';
        printLine(data);
    }
}
