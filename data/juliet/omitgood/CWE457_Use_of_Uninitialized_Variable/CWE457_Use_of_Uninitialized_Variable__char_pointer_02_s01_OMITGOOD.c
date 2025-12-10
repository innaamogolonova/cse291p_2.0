#include "std_testcase.h"
#include <wchar.h>
static void goodB2G1()
{
    char * data;
    if(1)
    {
        ;
    }
    if(0)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = "string";
        printLine(data);
    }
}
static void goodB2G2()
{
    char * data;
    if(1)
    {
        ;
    }
    if(1)
    {
        data = "string";
        printLine(data);
    }
}
static void goodG2B1()
{
    char * data;
    if(0)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = "string";
    }
    if(1)
    {
        printLine(data);
    }
}
static void goodG2B2()
{
    char * data;
    if(1)
    {
        data = "string";
    }
    if(1)
    {
        printLine(data);
    }
}
void CWE457_Use_of_Uninitialized_Variable__char_pointer_02_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}
