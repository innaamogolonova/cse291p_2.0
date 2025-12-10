#include "std_testcase.h"
#include <math.h>
static void goodB2G1()
{
    short data;
    data = 0;
    if(staticReturnsTrue())
    {
        fscanf (stdin, "%hd", &data);
    }
    if(staticReturnsFalse())
    {
        printLine("Benign, fixed string");
    }
    else
    {
        if (abs((long)data) <= (long)sqrt((double)SHRT_MAX))
        {
            short result = data * data;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
static void goodB2G2()
{
    short data;
    data = 0;
    if(staticReturnsTrue())
    {
        fscanf (stdin, "%hd", &data);
    }
    if(staticReturnsTrue())
    {
        if (abs((long)data) <= (long)sqrt((double)SHRT_MAX))
        {
            short result = data * data;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
static void goodG2B1()
{
    short data;
    data = 0;
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
            short result = data * data;
            printIntLine(result);
        }
    }
}
static void goodG2B2()
{
    short data;
    data = 0;
    if(staticReturnsTrue())
    {
        data = 2;
    }
    if(staticReturnsTrue())
    {
        {
            short result = data * data;
            printIntLine(result);
        }
    }
}
void CWE190_Integer_Overflow__short_fscanf_square_08_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}
