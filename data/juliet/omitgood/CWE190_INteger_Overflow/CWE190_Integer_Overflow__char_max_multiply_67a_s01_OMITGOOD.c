#include "std_testcase.h"
void CWE190_Integer_Overflow__char_max_multiply_67b_goodG2BSink(CWE190_Integer_Overflow__char_max_multiply_67_structType myStruct);
static void goodG2B()
{
    char data;
    CWE190_Integer_Overflow__char_max_multiply_67_structType myStruct;
    data = ' ';
    data = 2;
    myStruct.structFirst = data;
    CWE190_Integer_Overflow__char_max_multiply_67b_goodG2BSink(myStruct);
}
void CWE190_Integer_Overflow__char_max_multiply_67b_goodB2GSink(CWE190_Integer_Overflow__char_max_multiply_67_structType myStruct);
static void goodB2G()
{
    char data;
    CWE190_Integer_Overflow__char_max_multiply_67_structType myStruct;
    data = ' ';
    data = CHAR_MAX;
    myStruct.structFirst = data;
    CWE190_Integer_Overflow__char_max_multiply_67b_goodB2GSink(myStruct);
}
void CWE190_Integer_Overflow__char_max_multiply_67_good()
{
    goodG2B();
    goodB2G();
}
