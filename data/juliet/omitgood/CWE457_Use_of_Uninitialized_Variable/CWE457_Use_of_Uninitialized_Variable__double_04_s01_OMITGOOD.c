#include "std_testcase.h"
#include <wchar.h>
static void goodB2G1()
{
    double data;
    if(STATIC_CONST_TRUE)
    {
        ;
    }
    if(STATIC_CONST_FALSE)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = 5.0;
        printDoubleLine(data);
    }
}
static void goodB2G2()
{
    double data;
    if(STATIC_CONST_TRUE)
    {
        ;
    }
    if(STATIC_CONST_TRUE)
    {
        data = 5.0;
        printDoubleLine(data);
    }
}
static void goodG2B1()
{
    double data;
    if(STATIC_CONST_FALSE)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = 5.0;
    }
    if(STATIC_CONST_TRUE)
    {
        printDoubleLine(data);
    }
}
static void goodG2B2()
{
    double data;
    if(STATIC_CONST_TRUE)
    {
        data = 5.0;
    }
    if(STATIC_CONST_TRUE)
    {
        printDoubleLine(data);
    }
}
void CWE457_Use_of_Uninitialized_Variable__double_04_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}
