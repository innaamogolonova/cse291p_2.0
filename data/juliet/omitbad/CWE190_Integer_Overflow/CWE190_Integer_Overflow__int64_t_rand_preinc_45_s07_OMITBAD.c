#include "std_testcase.h"
static void badSink()
{
    int64_t data = CWE190_Integer_Overflow__int64_t_rand_preinc_45_badData;
    {
        ++data;
        int64_t result = data;
        printLongLongLine(result);
    }
}
void CWE190_Integer_Overflow__int64_t_rand_preinc_45_bad()
{
    int64_t data;
    data = 0LL;
    data = (int64_t)RAND64();
    CWE190_Integer_Overflow__int64_t_rand_preinc_45_badData = data;
    badSink();
}
