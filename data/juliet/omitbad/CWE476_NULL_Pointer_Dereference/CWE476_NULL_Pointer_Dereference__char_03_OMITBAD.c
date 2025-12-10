#include "std_testcase.h"
#include <wchar.h>
void CWE476_NULL_Pointer_Dereference__char_03_bad()
{
    char * data;
    if(5==5)
    {
        data = NULL;
    }
    if(5==5)
    {
        printHexCharLine(data[0]);
    }
}
