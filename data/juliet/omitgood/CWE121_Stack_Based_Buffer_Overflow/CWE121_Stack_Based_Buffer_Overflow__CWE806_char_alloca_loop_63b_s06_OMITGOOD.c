#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_loop_63b_goodG2BSink(char * * dataPtr)
{
    char * data = *dataPtr;
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
