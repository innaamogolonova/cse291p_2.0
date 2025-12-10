#include "std_testcase.h"
static void goodG2B()
{
    char data;
    data = ' ';
    data = 2;
    {
        char result = data + 1;
        printHexCharLine(result);
    }
}
static void goodB2G()
{
    char data;
    data = ' ';
    data = (char)RAND32();
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
void CWE190_Integer_Overflow__char_rand_add_01_good()
{
    goodG2B();
    goodB2G();
}
