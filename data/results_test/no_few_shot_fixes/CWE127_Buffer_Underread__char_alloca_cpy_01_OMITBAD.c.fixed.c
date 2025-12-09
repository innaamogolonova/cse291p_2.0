--- BEGIN SOURCE.C ---
#include "std_testcase.h"
#include <wchar.h>
void CWE127_Buffer_Underread__char_alloca_cpy_01_bad()
{
    char * data;
    char dataBuffer[100]; // Changed from alloca to a variable length array
    memset(dataBuffer, 'A', 100-1);
    dataBuffer[100-1] = '\0';
    data = dataBuffer; // Removed the underread by not subtracting from dataBuffer
    {
        char dest[100*2];
        memset(dest, 'C', 100*2-1);
        dest[100*2-1] = '\0';
        strcpy(dest, data);
        printLine(dest);
    }
}

--- END SOURCE.C ---