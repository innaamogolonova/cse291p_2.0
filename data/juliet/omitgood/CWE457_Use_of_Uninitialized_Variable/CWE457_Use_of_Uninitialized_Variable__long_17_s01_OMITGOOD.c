#include "std_testcase.h"
#include <wchar.h>
static void goodB2G()
{
    int i,k;
    long data;
    for(i = 0; i < 1; i++)
    {
        ;
    }
    for(k = 0; k < 1; k++)
    {
        data = 5L;
        printLongLine(data);
    }
}
static void goodG2B()
{
    int h,j;
    long data;
    for(h = 0; h < 1; h++)
    {
        data = 5L;
    }
    for(j = 0; j < 1; j++)
    {
        printLongLine(data);
    }
}
void CWE457_Use_of_Uninitialized_Variable__long_17_good()
{
    goodB2G();
    goodG2B();
}
