#include "std_testcase.h"
static char goodG2BSource(char data)
{
    data = 2;
    return data;
}
static void goodG2B()
{
    char data;
    data = ' ';
    data = goodG2BSource(data);
    {
        ++data;
        char result = data;
        printHexCharLine(result);
    }
}
static char goodB2GSource(char data)
{
    fscanf (stdin, "%c", &data);
    return data;
}
static void goodB2G()
{
    char data;
    data = ' ';
    data = goodB2GSource(data);
    if (data < CHAR_MAX)
    {
        ++data;
        char result = data;
        printHexCharLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}
void CWE190_Integer_Overflow__char_fscanf_preinc_42_good()
{
    goodB2G();
    goodG2B();
}
