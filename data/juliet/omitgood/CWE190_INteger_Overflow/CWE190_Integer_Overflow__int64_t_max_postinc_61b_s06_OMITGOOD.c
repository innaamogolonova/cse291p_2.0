#include "std_testcase.h"
int64_t CWE190_Integer_Overflow__int64_t_max_postinc_61b_goodG2BSource(int64_t data)
{
    data = 2;
    return data;
}
int64_t CWE190_Integer_Overflow__int64_t_max_postinc_61b_goodB2GSource(int64_t data)
{
    data = LLONG_MAX;
    return data;
}
