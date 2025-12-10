#include "std_testcase.h"
extern int CWE190_Integer_Overflow__char_rand_postinc_22_goodB2G1Global;
extern int CWE190_Integer_Overflow__char_rand_postinc_22_goodB2G2Global;
extern int CWE190_Integer_Overflow__char_rand_postinc_22_goodG2BGlobal;
void CWE190_Integer_Overflow__char_rand_postinc_22_goodB2G1Sink(char data)
{
    if(CWE190_Integer_Overflow__char_rand_postinc_22_goodB2G1Global)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        if (data < CHAR_MAX)
        {
            data++;
            char result = data;
            printHexCharLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
void CWE190_Integer_Overflow__char_rand_postinc_22_goodB2G2Sink(char data)
{
    if(CWE190_Integer_Overflow__char_rand_postinc_22_goodB2G2Global)
    {
        if (data < CHAR_MAX)
        {
            data++;
            char result = data;
            printHexCharLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
void CWE190_Integer_Overflow__char_rand_postinc_22_goodG2BSink(char data)
{
    if(CWE190_Integer_Overflow__char_rand_postinc_22_goodG2BGlobal)
    {
        {
            data++;
            char result = data;
            printHexCharLine(result);
        }
    }
}
