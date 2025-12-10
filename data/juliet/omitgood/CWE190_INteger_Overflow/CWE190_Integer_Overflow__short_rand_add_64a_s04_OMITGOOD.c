#include "std_testcase.h"
void CWE190_Integer_Overflow__short_rand_add_64b_goodG2BSink(void * dataVoidPtr);
static void goodG2B()
{
    short data;
    data = 0;
    data = 2;
    CWE190_Integer_Overflow__short_rand_add_64b_goodG2BSink(&data);
}
void CWE190_Integer_Overflow__short_rand_add_64b_goodB2GSink(void * dataVoidPtr);
static void goodB2G()
{
    short data;
    data = 0;
    data = (short)RAND32();
    CWE190_Integer_Overflow__short_rand_add_64b_goodB2GSink(&data);
}
void CWE190_Integer_Overflow__short_rand_add_64_good()
{
    goodG2B();
    goodB2G();
}
