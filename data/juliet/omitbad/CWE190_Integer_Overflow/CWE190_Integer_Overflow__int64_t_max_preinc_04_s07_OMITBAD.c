#include "std_testcase.h"
void CWE190_Integer_Overflow__int64_t_max_preinc_04_bad()
{
    int64_t data;
    data = 0LL;
    if(STATIC_CONST_TRUE)
    {
        data = LLONG_MAX;
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
