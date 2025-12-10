#include "std_testcase.h"
static void badSink()
{
    unsigned int data = CWE190_Integer_Overflow__unsigned_int_max_preinc_45_badData;
    {
        ++data;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}
void CWE190_Integer_Overflow__unsigned_int_max_preinc_45_bad()
{
    unsigned int data;
    data = 0;
    data = UINT_MAX;
    CWE190_Integer_Overflow__unsigned_int_max_preinc_45_badData = data;
    badSink();
}
