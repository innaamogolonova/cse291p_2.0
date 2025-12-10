#include "std_testcase.h"
#include <math.h>
void CWE190_Integer_Overflow__int_fscanf_square_52c_goodG2BSink(int data)
{
    {
        int result = data * data;
        printIntLine(result);
    }
}
void CWE190_Integer_Overflow__int_fscanf_square_52c_goodB2GSink(int data)
{
    if (data > INT_MIN && abs(data) < (long)sqrt((double)INT_MAX))
    {
        int result = data * data;
        printIntLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}
