#include "std_testcase.h"
void CWE190_Integer_Overflow__unsigned_int_rand_preinc_31_bad()
{
    unsigned int data;
    data = 0;
    data = (unsigned int)RAND32();
    {
        unsigned int dataCopy = data;
        unsigned int data = dataCopy;
        {
            ++data;
            unsigned int result = data;
            printUnsignedLine(result);
        }
    }
}
