#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE805_char_alloca_memmove_67b_badSink(CWE121_Stack_Based_Buffer_Overflow__CWE805_char_alloca_memmove_67_structType myStruct)
{
    char * data = myStruct.structFirst;
    {
        char source[100];
        memset(source, 'C', 100-1);
        source[100-1] = '\0';
        memmove(data, source, 100*sizeof(char));
        data[100-1] = '\0';
        printLine(data);
    }
}
