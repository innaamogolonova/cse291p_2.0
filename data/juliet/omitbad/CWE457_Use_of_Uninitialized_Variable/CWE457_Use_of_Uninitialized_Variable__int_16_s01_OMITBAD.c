#include "std_testcase.h"
#include <wchar.h>
void CWE457_Use_of_Uninitialized_Variable__int_16_bad()
{
    int data;
    while(1)
    {
        ;
        break;
    }
    while(1)
    {
        printIntLine(data);
        break;
    }
}
