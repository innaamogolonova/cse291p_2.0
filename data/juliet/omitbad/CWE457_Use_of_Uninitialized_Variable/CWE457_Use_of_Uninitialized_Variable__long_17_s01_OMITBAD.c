#include "std_testcase.h"
#include <wchar.h>
void CWE457_Use_of_Uninitialized_Variable__long_17_bad()
{
    int i,j;
    long data;
    for(i = 0; i < 1; i++)
    {
        ;
    }
    for(j = 0; j < 1; j++)
    {
        printLongLine(data);
    }
}
