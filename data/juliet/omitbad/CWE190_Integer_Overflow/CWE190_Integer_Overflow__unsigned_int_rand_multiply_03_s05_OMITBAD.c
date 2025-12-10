#include "std_testcase.h"
void CWE190_Integer_Overflow__unsigned_int_rand_multiply_03_bad()
{
    unsigned int data;
    data = 0;
    if(5==5)
    {
        data = (unsigned int)RAND32();
    }
    if(5==5)
    {
        if(data > 0)
        {
            unsigned int result = data * 2;
            printUnsignedLine(result);
        }
    }
}
