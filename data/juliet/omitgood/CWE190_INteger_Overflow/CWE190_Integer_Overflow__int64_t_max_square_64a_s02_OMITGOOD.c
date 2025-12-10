#include "std_testcase.h"
#include <math.h>
void CWE190_Integer_Overflow__int64_t_max_square_64b_goodG2BSink(void * dataVoidPtr);
static void goodG2B()
{
    int64_t data;
    data = 0LL;
    data = 2;
    CWE190_Integer_Overflow__int64_t_max_square_64b_goodG2BSink(&data);
}
void CWE190_Integer_Overflow__int64_t_max_square_64b_goodB2GSink(void * dataVoidPtr);
static void goodB2G()
{
    int64_t data;
    data = 0LL;
    data = LLONG_MAX;
    CWE190_Integer_Overflow__int64_t_max_square_64b_goodB2GSink(&data);
}
void CWE190_Integer_Overflow__int64_t_max_square_64_good()
{
    goodG2B();
    goodB2G();
}
