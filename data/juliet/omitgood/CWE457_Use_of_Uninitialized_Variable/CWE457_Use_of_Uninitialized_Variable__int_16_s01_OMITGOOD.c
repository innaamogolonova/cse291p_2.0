#include "std_testcase.h"
#include <wchar.h>
static void goodB2G()
{
    int data;
    while(1)
    {
        ;
        break;
    }
    while(1)
    {
        data = 5;
        printIntLine(data);
        break;
    }
}
static void goodG2B()
{
    int data;
    while(1)
    {
        data = 5;
        break;
    }
    while(1)
    {
        printIntLine(data);
        break;
    }
}
void CWE457_Use_of_Uninitialized_Variable__int_16_good()
{
    goodB2G();
    goodG2B();
}
