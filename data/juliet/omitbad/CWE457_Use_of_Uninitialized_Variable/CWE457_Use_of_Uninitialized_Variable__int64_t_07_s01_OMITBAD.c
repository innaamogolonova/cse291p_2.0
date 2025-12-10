#include "std_testcase.h"
#include <wchar.h>
void CWE457_Use_of_Uninitialized_Variable__int64_t_07_bad()
{
    int64_t data;
    if(staticFive==5)
    {
        ;
    }
    if(staticFive==5)
    {
        printLongLongLine(data);
    }
}
