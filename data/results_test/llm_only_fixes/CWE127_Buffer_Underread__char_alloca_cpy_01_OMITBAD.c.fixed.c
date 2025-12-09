#include "std_testcase.h"
#include <wchar.h>
void CWE127_Buffer_Underread__char_alloca_cpy_01_bad()
{
    char * data;
    char * dataBuffer = (char *)ALLOCA(100*sizeof(char));
    memset(dataBuffer, 'A', 100-1);
    dataBuffer[100-1] = '\0';
    data = dataBuffer; // Fix: Point data to the start of dataBuffer
    {
        char dest[100*2];
        memset(dest, 'C', 100*2-1);
        dest[100*2-1] = '\0';
        strncpy(dest, data, sizeof(dest) - 1);
        dest[sizeof(dest) - 1] = '\0';
        printLine(dest);
    }
}