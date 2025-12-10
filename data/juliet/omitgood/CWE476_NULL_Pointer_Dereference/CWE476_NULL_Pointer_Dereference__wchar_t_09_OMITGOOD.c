#include "std_testcase.h"
#include <wchar.h>
static void goodB2G1()
{
    wchar_t * data;
    if(GLOBAL_CONST_TRUE)
    {
        data = NULL;
    }
    if(GLOBAL_CONST_FALSE)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        if (data != NULL)
        {
            printWcharLine(data[0]);
        }
        else
        {
            printLine("data is NULL");
        }
    }
}
static void goodB2G2()
{
    wchar_t * data;
    if(GLOBAL_CONST_TRUE)
    {
        data = NULL;
    }
    if(GLOBAL_CONST_TRUE)
    {
        if (data != NULL)
        {
            printWcharLine(data[0]);
        }
        else
        {
            printLine("data is NULL");
        }
    }
}
static void goodG2B1()
{
    wchar_t * data;
    if(GLOBAL_CONST_FALSE)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = L"Good";
    }
    if(GLOBAL_CONST_TRUE)
    {
        printWcharLine(data[0]);
    }
}
static void goodG2B2()
{
    wchar_t * data;
    if(GLOBAL_CONST_TRUE)
    {
        data = L"Good";
    }
    if(GLOBAL_CONST_TRUE)
    {
        printWcharLine(data[0]);
    }
}
void CWE476_NULL_Pointer_Dereference__wchar_t_09_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}
