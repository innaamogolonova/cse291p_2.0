#include "std_testcase.h"
void CWE190_Integer_Overflow__unsigned_int_rand_add_52c_badSink(unsigned int data)
{
    {
        unsigned int result = data + 1;
        printUnsignedLine(result);
    }
}
