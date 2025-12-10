#include "std_testcase.h"
int64_t CWE190_Integer_Overflow__int64_t_max_postinc_61b_badSource(int64_t data)
{
    data = LLONG_MAX;
    return data;
}
