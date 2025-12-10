#include "std_testcase.h"
void CWE190_Integer_Overflow__unsigned_int_max_add_63b_badSink(unsigned int * dataPtr);
void CWE190_Integer_Overflow__unsigned_int_max_add_63_bad()
{
    unsigned int data;
    data = 0;
    data = UINT_MAX;
    CWE190_Integer_Overflow__unsigned_int_max_add_63b_badSink(&data);
}
