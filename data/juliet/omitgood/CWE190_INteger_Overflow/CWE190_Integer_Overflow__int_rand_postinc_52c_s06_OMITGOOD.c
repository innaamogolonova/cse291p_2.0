#include "std_testcase.h"
void CWE190_Integer_Overflow__int_rand_postinc_52c_goodG2BSink(int data)
{
    {
        data++;
        int result = data;
        printIntLine(result);
    }
}
void CWE190_Integer_Overflow__int_rand_postinc_52c_goodB2GSink(int data)
{
    if (data < INT_MAX)
    {
        data++;
        int result = data;
        printIntLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}
