#include "std_testcase.h"
#include <math.h>
void CWE190_Integer_Overflow__char_rand_square_67b_goodG2BSink(CWE190_Integer_Overflow__char_rand_square_67_structType myStruct);
static void goodG2B()
{
    char data;
    CWE190_Integer_Overflow__char_rand_square_67_structType myStruct;
    data = ' ';
    data = 2;
    myStruct.structFirst = data;
    CWE190_Integer_Overflow__char_rand_square_67b_goodG2BSink(myStruct);
}
void CWE190_Integer_Overflow__char_rand_square_67b_goodB2GSink(CWE190_Integer_Overflow__char_rand_square_67_structType myStruct);
static void goodB2G()
{
    char data;
    CWE190_Integer_Overflow__char_rand_square_67_structType myStruct;
    data = ' ';
    data = (char)RAND32();
    myStruct.structFirst = data;
    CWE190_Integer_Overflow__char_rand_square_67b_goodB2GSink(myStruct);
}
void CWE190_Integer_Overflow__char_rand_square_67_good()
{
    goodG2B();
    goodB2G();
}
