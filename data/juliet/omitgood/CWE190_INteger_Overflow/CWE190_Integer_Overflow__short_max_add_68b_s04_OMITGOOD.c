#include "std_testcase.h"
void CWE190_Integer_Overflow__short_max_add_68b_goodG2BSink()
{
    short data = CWE190_Integer_Overflow__short_max_add_68_goodG2BData;
    {
        short result = data + 1;
        printIntLine(result);
    }
}
void CWE190_Integer_Overflow__short_max_add_68b_goodB2GSink()
{
    short data = CWE190_Integer_Overflow__short_max_add_68_goodB2GData;
    if (data < SHRT_MAX)
    {
        short result = data + 1;
        printIntLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}
