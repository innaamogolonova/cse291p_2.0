#include "std_testcase.h"
void CWE190_Integer_Overflow__int_rand_postinc_52c_badSink(int data)
{
    {
        data++;
        int result = data;
        printIntLine(result);
    }
}
