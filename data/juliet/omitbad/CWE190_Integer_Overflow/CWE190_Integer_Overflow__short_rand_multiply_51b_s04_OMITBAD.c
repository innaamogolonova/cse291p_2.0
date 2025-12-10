#include "std_testcase.h"
void CWE190_Integer_Overflow__short_rand_multiply_51b_badSink(short data)
{
    if(data > 0)
    {
        short result = data * 2;
        printIntLine(result);
    }
}
