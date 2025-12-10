#include "std_testcase.h"
#include <wchar.h>
void CWE457_Use_of_Uninitialized_Variable__struct_pointer_02_bad()
{
    twoIntsStruct * data;
    if(1)
    {
        ;
    }
    if(1)
    {
        printIntLine(data->intOne);
        printIntLine(data->intTwo);
    }
}
