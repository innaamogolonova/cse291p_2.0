#include "std_testcase.h"
void CWE190_Integer_Overflow__unsigned_int_max_add_63b_goodG2BSink(unsigned int * data);
static void goodG2B()
{
    unsigned int data;
    data = 0;
    data = 2;
    CWE190_Integer_Overflow__unsigned_int_max_add_63b_goodG2BSink(&data);
}
void CWE190_Integer_Overflow__unsigned_int_max_add_63b_goodB2GSink(unsigned int * data);
static void goodB2G()
{
    unsigned int data;
    data = 0;
    data = UINT_MAX;
    CWE190_Integer_Overflow__unsigned_int_max_add_63b_goodB2GSink(&data);
}
void CWE190_Integer_Overflow__unsigned_int_max_add_63_good()
{
    goodG2B();
    goodB2G();
}
