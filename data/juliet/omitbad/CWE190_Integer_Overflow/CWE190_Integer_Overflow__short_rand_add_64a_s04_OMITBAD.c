#include "std_testcase.h"
void CWE190_Integer_Overflow__short_rand_add_64b_badSink(void * dataVoidPtr);
void CWE190_Integer_Overflow__short_rand_add_64_bad()
{
    short data;
    data = 0;
    data = (short)RAND32();
    CWE190_Integer_Overflow__short_rand_add_64b_badSink(&data);
}
