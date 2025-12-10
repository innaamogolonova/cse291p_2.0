#include "std_testcase.h"
static void goodB2G1()
{
    int64_t data;
    data = 0LL;
    if(STATIC_CONST_TRUE)
    {
        data = LLONG_MAX;
    }
    if(STATIC_CONST_FALSE)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        if (data < LLONG_MAX)
        {
            ++data;
            int64_t result = data;
            printLongLongLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
static void goodB2G2()
{
    int64_t data;
    data = 0LL;
    if(STATIC_CONST_TRUE)
    {
        data = LLONG_MAX;
    }
    if(STATIC_CONST_TRUE)
    {
        if (data < LLONG_MAX)
        {
            ++data;
            int64_t result = data;
            printLongLongLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
static void goodG2B1()
{
    int64_t data;
    data = 0LL;
    if(STATIC_CONST_FALSE)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = 2;
    }
    if(STATIC_CONST_TRUE)
    {
        {
            ++data;
            int64_t result = data;
            printLongLongLine(result);
        }
    }
}
static void goodG2B2()
{
    int64_t data;
    data = 0LL;
    if(STATIC_CONST_TRUE)
    {
        data = 2;
    }
    if(STATIC_CONST_TRUE)
    {
        {
            ++data;
            int64_t result = data;
            printLongLongLine(result);
        }
    }
}
void CWE190_Integer_Overflow__int64_t_max_preinc_04_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}
