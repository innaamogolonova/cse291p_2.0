#include "std_testcase.h"
void CWE190_Integer_Overflow__unsigned_int_rand_add_52c_goodG2BSink(unsigned int data)
{
    {
        unsigned int result = data + 1;
        printUnsignedLine(result);
    }
}
void CWE190_Integer_Overflow__unsigned_int_rand_add_52c_goodB2GSink(unsigned int data)
{
    if (data < UINT_MAX)
    {
        unsigned int result = data + 1;
        printUnsignedLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}
