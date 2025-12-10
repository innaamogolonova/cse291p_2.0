#include "std_testcase.h"
static void goodG2BSink()
{
    int64_t data = CWE190_Integer_Overflow__int64_t_rand_preinc_45_goodG2BData;
    {
        ++data;
        int64_t result = data;
        printLongLongLine(result);
    }
}
static void goodG2B()
{
    int64_t data;
    data = 0LL;
    data = 2;
    CWE190_Integer_Overflow__int64_t_rand_preinc_45_goodG2BData = data;
    goodG2BSink();
}
static void goodB2GSink()
{
    int64_t data = CWE190_Integer_Overflow__int64_t_rand_preinc_45_goodB2GData;
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
static void goodB2G()
{
    int64_t data;
    data = 0LL;
    data = (int64_t)RAND64();
    CWE190_Integer_Overflow__int64_t_rand_preinc_45_goodB2GData = data;
    goodB2GSink();
}
void CWE190_Integer_Overflow__int64_t_rand_preinc_45_good()
{
    goodG2B();
    goodB2G();
}
