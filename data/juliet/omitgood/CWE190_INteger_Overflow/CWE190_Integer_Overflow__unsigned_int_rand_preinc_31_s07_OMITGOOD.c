#include "std_testcase.h"
static void goodG2B()
{
    unsigned int data;
    data = 0;
    data = 2;
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
static void goodB2G()
{
    unsigned int data;
    data = 0;
    data = (unsigned int)RAND32();
    {
        unsigned int dataCopy = data;
        unsigned int data = dataCopy;
        if (data < UINT_MAX)
        {
            ++data;
            unsigned int result = data;
            printUnsignedLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
void CWE190_Integer_Overflow__unsigned_int_rand_preinc_31_good()
{
    goodG2B();
    goodB2G();
}
