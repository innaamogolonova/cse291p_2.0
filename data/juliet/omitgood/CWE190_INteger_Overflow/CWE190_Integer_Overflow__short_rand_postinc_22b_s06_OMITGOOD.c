#include "std_testcase.h"
extern int CWE190_Integer_Overflow__short_rand_postinc_22_goodB2G1Global;
extern int CWE190_Integer_Overflow__short_rand_postinc_22_goodB2G2Global;
extern int CWE190_Integer_Overflow__short_rand_postinc_22_goodG2BGlobal;
void CWE190_Integer_Overflow__short_rand_postinc_22_goodB2G1Sink(short data)
{
    if(CWE190_Integer_Overflow__short_rand_postinc_22_goodB2G1Global)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        if (data < SHRT_MAX)
        {
            data++;
            short result = data;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
void CWE190_Integer_Overflow__short_rand_postinc_22_goodB2G2Sink(short data)
{
    if(CWE190_Integer_Overflow__short_rand_postinc_22_goodB2G2Global)
    {
        if (data < SHRT_MAX)
        {
            data++;
            short result = data;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
void CWE190_Integer_Overflow__short_rand_postinc_22_goodG2BSink(short data)
{
    if(CWE190_Integer_Overflow__short_rand_postinc_22_goodG2BGlobal)
    {
        {
            data++;
            short result = data;
            printIntLine(result);
        }
    }
}
