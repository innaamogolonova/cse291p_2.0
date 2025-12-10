#include "std_testcase.h"
static int goodB2G1Static = 0;
static int goodB2G2Static = 0;
static int goodG2BStatic = 0;
static void goodB2G1Sink(int64_t data)
{
    if(goodB2G1Static)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        if(data > 0)
        {
            if (data < (LLONG_MAX/2))
            {
                int64_t result = data * 2;
                printLongLongLine(result);
            }
            else
            {
                printLine("data value is too large to perform arithmetic safely.");
            }
        }
    }
}
static void goodB2G1()
{
    int64_t data;
    data = 0LL;
    data = LLONG_MAX;
    goodB2G1Static = 0;
    goodB2G1Sink(data);
}
static void goodB2G2Sink(int64_t data)
{
    if(goodB2G2Static)
    {
        if(data > 0)
        {
            if (data < (LLONG_MAX/2))
            {
                int64_t result = data * 2;
                printLongLongLine(result);
            }
            else
            {
                printLine("data value is too large to perform arithmetic safely.");
            }
        }
    }
}
static void goodB2G2()
{
    int64_t data;
    data = 0LL;
    data = LLONG_MAX;
    goodB2G2Static = 1;
    goodB2G2Sink(data);
}
static void goodG2BSink(int64_t data)
{
    if(goodG2BStatic)
    {
        if(data > 0)
        {
            int64_t result = data * 2;
            printLongLongLine(result);
        }
    }
}
static void goodG2B()
{
    int64_t data;
    data = 0LL;
    data = 2;
    goodG2BStatic = 1;
    goodG2BSink(data);
}
void CWE190_Integer_Overflow__int64_t_max_multiply_21_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B();
}
