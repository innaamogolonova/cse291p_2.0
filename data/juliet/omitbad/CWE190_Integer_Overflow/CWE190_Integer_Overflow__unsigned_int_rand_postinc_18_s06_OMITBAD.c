#include "std_testcase.h"
void CWE190_Integer_Overflow__unsigned_int_rand_postinc_18_bad()
{
    unsigned int data;
    data = 0;
    goto source;
source:
    data = (unsigned int)RAND32();
    goto sink;
sink:
    {
        data++;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}
