#include "std_testcase.h"
static void goodB2G1()
{
    short data;
    data = 0;
    if(staticFive==5)
    {
        data = (short)RAND32();
    }
    if(staticFive!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        if (data < SHRT_MAX)
        {
            ++data;
            short result = data;
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
    if(staticFive==5)
    {
        data = (short)RAND32();
    }
    if(staticFive==5)
    {
        if (data < SHRT_MAX)
        {
            ++data;
            short result = data;
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
    if(staticFive!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = 2;
    }
    if(staticFive==5)
    {
        {
            ++data;
            short result = data;
            printIntLine(result);
        }
    }
}
static void goodG2B2()
{
    short data;
    data = 0;
    if(staticFive==5)
    {
        data = 2;
    }
    if(staticFive==5)
    {
        {
            ++data;
            short result = data;
            printIntLine(result);
        }
    }
}
void CWE190_Integer_Overflow__short_rand_preinc_07_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}
