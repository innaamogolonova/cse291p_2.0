#include "std_testcase.h"
int CWE190_Integer_Overflow__int_max_add_22_goodB2G1Global = 0;
int CWE190_Integer_Overflow__int_max_add_22_goodB2G2Global = 0;
int CWE190_Integer_Overflow__int_max_add_22_goodG2BGlobal = 0;
void CWE190_Integer_Overflow__int_max_add_22_goodB2G1Sink(int data);
static void goodB2G1()
{
    int data;
    data = 0;
    data = INT_MAX;
    CWE190_Integer_Overflow__int_max_add_22_goodB2G1Global = 0;
    CWE190_Integer_Overflow__int_max_add_22_goodB2G1Sink(data);
}
void CWE190_Integer_Overflow__int_max_add_22_goodB2G2Sink(int data);
static void goodB2G2()
{
    int data;
    data = 0;
    data = INT_MAX;
    CWE190_Integer_Overflow__int_max_add_22_goodB2G2Global = 1;
    CWE190_Integer_Overflow__int_max_add_22_goodB2G2Sink(data);
}
void CWE190_Integer_Overflow__int_max_add_22_goodG2BSink(int data);
static void goodG2B()
{
    int data;
    data = 0;
    data = 2;
    CWE190_Integer_Overflow__int_max_add_22_goodG2BGlobal = 1;
    CWE190_Integer_Overflow__int_max_add_22_goodG2BSink(data);
}
void CWE190_Integer_Overflow__int_max_add_22_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B();
}
