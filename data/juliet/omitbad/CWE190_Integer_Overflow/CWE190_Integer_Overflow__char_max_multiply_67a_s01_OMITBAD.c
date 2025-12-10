#include "std_testcase.h"
void CWE190_Integer_Overflow__char_max_multiply_67b_badSink(CWE190_Integer_Overflow__char_max_multiply_67_structType myStruct);
void CWE190_Integer_Overflow__char_max_multiply_67_bad()
{
    char data;
    CWE190_Integer_Overflow__char_max_multiply_67_structType myStruct;
    data = ' ';
    data = CHAR_MAX;
    myStruct.structFirst = data;
    CWE190_Integer_Overflow__char_max_multiply_67b_badSink(myStruct);
}
