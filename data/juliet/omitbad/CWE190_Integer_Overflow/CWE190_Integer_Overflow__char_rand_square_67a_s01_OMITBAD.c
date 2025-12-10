#include "std_testcase.h"
#include <math.h>
void CWE190_Integer_Overflow__char_rand_square_67b_badSink(CWE190_Integer_Overflow__char_rand_square_67_structType myStruct);
void CWE190_Integer_Overflow__char_rand_square_67_bad()
{
    char data;
    CWE190_Integer_Overflow__char_rand_square_67_structType myStruct;
    data = ' ';
    data = (char)RAND32();
    myStruct.structFirst = data;
    CWE190_Integer_Overflow__char_rand_square_67b_badSink(myStruct);
}
