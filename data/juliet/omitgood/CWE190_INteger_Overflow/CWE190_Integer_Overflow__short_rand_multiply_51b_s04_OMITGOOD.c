#include "std_testcase.h"
void CWE190_Integer_Overflow__short_rand_multiply_51b_goodG2BSink(short data)
{
    if(data > 0)
    {
        short result = data * 2;
        printIntLine(result);
    }
}
void CWE190_Integer_Overflow__short_rand_multiply_51b_goodB2GSink(short data)
{
    if(data > 0)
    {
        if (data < (SHRT_MAX/2))
        {
            short result = data * 2;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
