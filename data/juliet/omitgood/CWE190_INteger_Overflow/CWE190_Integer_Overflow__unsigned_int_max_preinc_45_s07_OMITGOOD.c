#include "std_testcase.h"
static void goodG2BSink()
{
    unsigned int data = CWE190_Integer_Overflow__unsigned_int_max_preinc_45_goodG2BData;
    {
        ++data;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}
static void goodG2B()
{
    unsigned int data;
    data = 0;
    data = 2;
    CWE190_Integer_Overflow__unsigned_int_max_preinc_45_goodG2BData = data;
    goodG2BSink();
}
static void goodB2GSink()
{
    unsigned int data = CWE190_Integer_Overflow__unsigned_int_max_preinc_45_goodB2GData;
    if (data < UINT_MAX)
    {
        ++data;
        unsigned int result = data;
        printUnsignedLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}
static void goodB2G()
{
    unsigned int data;
    data = 0;
    data = UINT_MAX;
    CWE190_Integer_Overflow__unsigned_int_max_preinc_45_goodB2GData = data;
    goodB2GSink();
}
void CWE190_Integer_Overflow__unsigned_int_max_preinc_45_good()
{
    goodG2B();
    goodB2G();
}
