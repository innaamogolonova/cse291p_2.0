#include "std_testcase.h"
static void goodB2G1()
{
    int64_t data;
    data = 0LL;
    if(globalFive==5)
    {
        data = (int64_t)RAND64();
    }
    if(globalFive!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        if (data < LLONG_MAX)
        {
            int64_t result = data + 1;
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
    if(globalFive==5)
    {
        data = (int64_t)RAND64();
    }
    if(globalFive==5)
    {
        if (data < LLONG_MAX)
        {
            int64_t result = data + 1;
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
            int64_t result = data + 1;
            printLongLongLine(result);
        }
    }
}
static void goodG2B2()
{
    int64_t data;
    data = 0LL;
    if(globalFive==5)
    {
        data = 2;
    }
    if(globalFive==5)
    {
        {
            int64_t result = data + 1;
            printLongLongLine(result);
        }
    }
}
void CWE190_Integer_Overflow__int64_t_rand_add_14_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}
