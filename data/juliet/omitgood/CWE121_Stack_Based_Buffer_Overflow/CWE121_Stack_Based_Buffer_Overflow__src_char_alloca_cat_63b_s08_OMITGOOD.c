#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cat_63b_goodG2BSink(char * * dataPtr)
{
    char * data = *dataPtr;
    {
        char dest[50] = "";
        strcat(dest, data);
        printLine(data);
    }
}
