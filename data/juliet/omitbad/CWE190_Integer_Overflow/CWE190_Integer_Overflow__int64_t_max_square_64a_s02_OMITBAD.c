#include "std_testcase.h"
#include <math.h>
void CWE190_Integer_Overflow__int64_t_max_square_64b_badSink(void * dataVoidPtr);
void CWE190_Integer_Overflow__int64_t_max_square_64_bad()
{
    int64_t data;
    data = 0LL;
    data = LLONG_MAX;
    CWE190_Integer_Overflow__int64_t_max_square_64b_badSink(&data);
}
