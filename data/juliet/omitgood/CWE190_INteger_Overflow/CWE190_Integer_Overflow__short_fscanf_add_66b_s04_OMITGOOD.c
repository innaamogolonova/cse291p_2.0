#include "std_testcase.h"
void CWE190_Integer_Overflow__short_fscanf_add_66b_goodG2BSink(short dataArray[])
{
    short data = dataArray[2];
    {
        short result = data + 1;
        printIntLine(result);
    }
}
void CWE190_Integer_Overflow__short_fscanf_add_66b_goodB2GSink(short dataArray[])
{
    short data = dataArray[2];
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
