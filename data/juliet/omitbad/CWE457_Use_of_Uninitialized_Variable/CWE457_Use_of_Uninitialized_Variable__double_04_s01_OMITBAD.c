#include "std_testcase.h"
#include <wchar.h>
void CWE457_Use_of_Uninitialized_Variable__double_04_bad()
{
    double data;
    if(STATIC_CONST_TRUE)
    {
        ;
    }
    if(STATIC_CONST_TRUE)
    {
        printDoubleLine(data);
    }
}
