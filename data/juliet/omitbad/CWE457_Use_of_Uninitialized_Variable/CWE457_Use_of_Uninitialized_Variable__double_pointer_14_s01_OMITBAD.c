#include "std_testcase.h"
#include <wchar.h>
void CWE457_Use_of_Uninitialized_Variable__double_pointer_14_bad()
{
    double * data;
    if(globalFive==5)
    {
        ;
    }
    if(globalFive==5)
    {
        printDoubleLine(*data);
    }
}
