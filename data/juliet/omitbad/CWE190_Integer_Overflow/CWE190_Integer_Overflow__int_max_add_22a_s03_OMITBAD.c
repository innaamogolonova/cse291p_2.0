#include "std_testcase.h"
int CWE190_Integer_Overflow__int_max_add_22_badGlobal = 0;
void CWE190_Integer_Overflow__int_max_add_22_badSink(int data);
void CWE190_Integer_Overflow__int_max_add_22_bad()
{
    int data;
    data = 0;
    data = INT_MAX;
    CWE190_Integer_Overflow__int_max_add_22_badGlobal = 1;
    CWE190_Integer_Overflow__int_max_add_22_badSink(data);
}
