#include "std_testcase.h"
int CWE190_Integer_Overflow__short_max_square_22_goodB2G1Global = 0;
int CWE190_Integer_Overflow__short_max_square_22_goodB2G2Global = 0;
int CWE190_Integer_Overflow__short_max_square_22_goodG2BGlobal = 0;
void CWE190_Integer_Overflow__short_max_square_22_goodB2G1Sink(short data);
static void goodB2G1()
{
    short data;
    data = 0;
    data = SHRT_MAX;
    CWE190_Integer_Overflow__short_max_square_22_goodB2G1Global = 0;
    CWE190_Integer_Overflow__short_max_square_22_goodB2G1Sink(data);
}
void CWE190_Integer_Overflow__short_max_square_22_goodB2G2Sink(short data);
static void goodB2G2()
{
    short data;
    data = 0;
    data = SHRT_MAX;
    CWE190_Integer_Overflow__short_max_square_22_goodB2G2Global = 1;
    CWE190_Integer_Overflow__short_max_square_22_goodB2G2Sink(data);
}
void CWE190_Integer_Overflow__short_max_square_22_goodG2BSink(short data);
static void goodG2B()
{
    short data;
    data = 0;
    data = 2;
    CWE190_Integer_Overflow__short_max_square_22_goodG2BGlobal = 1;
    CWE190_Integer_Overflow__short_max_square_22_goodG2BSink(data);
}
void CWE190_Integer_Overflow__short_max_square_22_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B();
}
