#include "std_testcase.h"
#include <math.h>
void CWE190_Integer_Overflow__int_max_square_63b_badSink(int * dataPtr);
void CWE190_Integer_Overflow__int_max_square_63_bad()
{
    int data;
    data = 0;
    data = INT_MAX;
    CWE190_Integer_Overflow__int_max_square_63b_badSink(&data);
}
