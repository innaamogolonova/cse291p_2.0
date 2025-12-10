#include "std_testcase.h"
#include <wchar.h>
void CWE457_Use_of_Uninitialized_Variable__int_pointer_09_bad()
{
    int * data;
    if(GLOBAL_CONST_TRUE)
    {
        ;
    }
    if(GLOBAL_CONST_TRUE)
    {
        printIntLine(*data);
    }
}
