#include "std_testcase.h"
#include <math.h>
void CWE190_Integer_Overflow__int_max_square_63b_goodG2BSink(int * data);
static void goodG2B()
{
    int data;
    data = 0;
    data = 2;
    CWE190_Integer_Overflow__int_max_square_63b_goodG2BSink(&data);
}
void CWE190_Integer_Overflow__int_max_square_63b_goodB2GSink(int * data);
static void goodB2G()
{
    int data;
    data = 0;
    data = INT_MAX;
    CWE190_Integer_Overflow__int_max_square_63b_goodB2GSink(&data);
}
void CWE190_Integer_Overflow__int_max_square_63_good()
{
    goodG2B();
    goodB2G();
}
