#include "std_testcase.h"
static void goodB2G1()
{
    char data;
    data = ' ';
    if(globalFive==5)
    {
        fscanf (stdin, "%c", &data);
    }
    if(globalFive!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        if (data < CHAR_MAX)
        {
            char result = data + 1;
            printHexCharLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
static void goodB2G2()
{
    char data;
    data = ' ';
    if(globalFive==5)
    {
        fscanf (stdin, "%c", &data);
    }
    if(globalFive==5)
    {
        if (data < CHAR_MAX)
        {
            char result = data + 1;
            printHexCharLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
static void goodG2B1()
{
    char data;
    data = ' ';
    if(globalFive!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = 2;
    }
    if(globalFive==5)
    {
        {
            char result = data + 1;
            printHexCharLine(result);
        }
    }
}
static void goodG2B2()
{
    char data;
    data = ' ';
    if(globalFive==5)
    {
        data = 2;
    }
    if(globalFive==5)
    {
        {
            char result = data + 1;
            printHexCharLine(result);
        }
    }
}
void CWE190_Integer_Overflow__char_fscanf_add_14_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}
