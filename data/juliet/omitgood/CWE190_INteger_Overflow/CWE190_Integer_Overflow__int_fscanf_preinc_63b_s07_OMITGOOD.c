#include "std_testcase.h"
void CWE190_Integer_Overflow__int_fscanf_preinc_63b_goodG2BSink(int * dataPtr)
{
    int data = *dataPtr;
    {
        ++data;
        int result = data;
        printIntLine(result);
    }
}
void CWE190_Integer_Overflow__int_fscanf_preinc_63b_goodB2GSink(int * dataPtr)
{
    int data = *dataPtr;
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
