#include "std_testcase.h"
#include <wchar.h>
static void goodB2G1()
{
    int64_t data;
    if(staticFive==5)
    {
        ;
    }
    if(staticFive!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = 5LL;
        printLongLongLine(data);
    }
}
static void goodB2G2()
{
    int64_t data;
    if(staticFive==5)
    {
        ;
    }
    if(staticFive==5)
    {
        data = 5LL;
        printLongLongLine(data);
    }
}
static void goodG2B1()
{
    int64_t data;
    if(staticFive!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = 5LL;
    }
    if(staticFive==5)
    {
        printLongLongLine(data);
    }
}
static void goodG2B2()
{
    int64_t data;
    if(staticFive==5)
    {
        data = 5LL;
    }
    if(staticFive==5)
    {
        printLongLongLine(data);
    }
}
void CWE457_Use_of_Uninitialized_Variable__int64_t_07_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}
