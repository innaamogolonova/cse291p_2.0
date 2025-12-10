#include "std_testcase.h"
#include <math.h>
static void goodB2G1()
{
    char data;
    data = ' ';
    if(staticReturnsTrue())
    {
        data = CHAR_MAX;
    }
    if(staticReturnsFalse())
    {
        printLine("Benign, fixed string");
    }
    else
    {
        if (abs((long)data) <= (long)sqrt((double)CHAR_MAX))
        {
            char result = data * data;
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
    if(staticReturnsTrue())
    {
        data = CHAR_MAX;
    }
    if(staticReturnsTrue())
    {
        if (abs((long)data) <= (long)sqrt((double)CHAR_MAX))
        {
            char result = data * data;
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
    if(staticReturnsFalse())
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = 2;
    }
    if(staticReturnsTrue())
    {
        {
            char result = data * data;
            printHexCharLine(result);
        }
    }
}
static void goodG2B2()
{
    char data;
    data = ' ';
    if(staticReturnsTrue())
    {
        data = 2;
    }
    if(staticReturnsTrue())
    {
        {
            char result = data * data;
            printHexCharLine(result);
        }
    }
}
void CWE190_Integer_Overflow__char_max_square_08_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}
