#include "std_testcase.h"
int CWE190_Integer_Overflow__char_max_preinc_22_goodB2G1Global = 0;
int CWE190_Integer_Overflow__char_max_preinc_22_goodB2G2Global = 0;
int CWE190_Integer_Overflow__char_max_preinc_22_goodG2BGlobal = 0;
void CWE190_Integer_Overflow__char_max_preinc_22_goodB2G1Sink(char data);
static void goodB2G1()
{
    char data;
    data = ' ';
    data = CHAR_MAX;
    CWE190_Integer_Overflow__char_max_preinc_22_goodB2G1Global = 0;
    CWE190_Integer_Overflow__char_max_preinc_22_goodB2G1Sink(data);
}
void CWE190_Integer_Overflow__char_max_preinc_22_goodB2G2Sink(char data);
static void goodB2G2()
{
    char data;
    data = ' ';
    data = CHAR_MAX;
    CWE190_Integer_Overflow__char_max_preinc_22_goodB2G2Global = 1;
    CWE190_Integer_Overflow__char_max_preinc_22_goodB2G2Sink(data);
}
void CWE190_Integer_Overflow__char_max_preinc_22_goodG2BSink(char data);
static void goodG2B()
{
    char data;
    data = ' ';
    data = 2;
    CWE190_Integer_Overflow__char_max_preinc_22_goodG2BGlobal = 1;
    CWE190_Integer_Overflow__char_max_preinc_22_goodG2BSink(data);
}
void CWE190_Integer_Overflow__char_max_preinc_22_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B();
}
