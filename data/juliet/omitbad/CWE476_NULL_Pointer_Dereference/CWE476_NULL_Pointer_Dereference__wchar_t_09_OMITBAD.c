#include "std_testcase.h"
#include <wchar.h>
void CWE476_NULL_Pointer_Dereference__wchar_t_09_bad()
{
    wchar_t * data;
    if(GLOBAL_CONST_TRUE)
    {
        data = NULL;
    }
    if(GLOBAL_CONST_TRUE)
    {
        printWcharLine(data[0]);
    }
}
