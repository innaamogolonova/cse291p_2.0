#include "std_testcase.h"
extern int CWE190_Integer_Overflow__int_fgets_preinc_22_goodB2G1Global;
extern int CWE190_Integer_Overflow__int_fgets_preinc_22_goodB2G2Global;
extern int CWE190_Integer_Overflow__int_fgets_preinc_22_goodG2BGlobal;
void CWE190_Integer_Overflow__int_fgets_preinc_22_goodB2G1Sink(int data)
{
    if(CWE190_Integer_Overflow__int_fgets_preinc_22_goodB2G1Global)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        if (data < INT_MAX)
        {
            ++data;
            int result = data;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
void CWE190_Integer_Overflow__int_fgets_preinc_22_goodB2G2Sink(int data)
{
    if(CWE190_Integer_Overflow__int_fgets_preinc_22_goodB2G2Global)
    {
        if (data < INT_MAX)
        {
            ++data;
            int result = data;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
void CWE190_Integer_Overflow__int_fgets_preinc_22_goodG2BSink(int data)
{
    if(CWE190_Integer_Overflow__int_fgets_preinc_22_goodG2BGlobal)
    {
        {
            ++data;
            int result = data;
            printIntLine(result);
        }
    }
}
