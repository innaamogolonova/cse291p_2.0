#include "std_testcase.h"
#include <wchar.h>
void CWE457_Use_of_Uninitialized_Variable__char_pointer_02_bad()
{
    char * data;
    if(1)
    {
        ;
    }
    if(1)
    {
        printLine(data);
    }
}
