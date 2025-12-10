#include "std_testcase.h"
#include <wchar.h>
static void goodB2G1()
{
    char * data;
    if(5==5)
    {
        data = NULL;
    }
    if(5!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        if (data != NULL)
        {
            printHexCharLine(data[0]);
        }
        else
        {
            printLine("data is NULL");
        }
    }
}
static void goodB2G2()
{
    char * data;
    if(5==5)
    {
        data = NULL;
    }
    if(5==5)
    {
        if (data != NULL)
        {
            printHexCharLine(data[0]);
        }
        else
        {
            printLine("data is NULL");
        }
    }
}
static void goodG2B1()
{
    char * data;
    if(5!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = "Good";
    }
    if(5==5)
    {
        printHexCharLine(data[0]);
    }
}
static void goodG2B2()
{
    char * data;
    if(5==5)
    {
        data = "Good";
    }
    if(5==5)
    {
        printHexCharLine(data[0]);
    }
}
void CWE476_NULL_Pointer_Dereference__char_03_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}
