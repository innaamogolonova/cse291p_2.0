#include "std_testcase.h"
void CWE190_Integer_Overflow__short_fscanf_preinc_52c_goodG2BSink(short data)
{
    {
        ++data;
        short result = data;
        printIntLine(result);
    }
}
void CWE190_Integer_Overflow__short_fscanf_preinc_52c_goodB2GSink(short data)
{
    if (data < SHRT_MAX)
    {
        ++data;
        short result = data;
        printIntLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}
