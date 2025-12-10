#include "std_testcase.h"
static void goodB2G()
{
    unsigned int data;
    data = 0;
    goto source;
source:
    fscanf (stdin, "%u", &data);
    goto sink;
sink:
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
static void goodG2B()
{
    unsigned int data;
    data = 0;
    goto source;
source:
    data = 2;
    goto sink;
sink:
    {
        ++data;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}
void CWE190_Integer_Overflow__unsigned_int_fscanf_preinc_18_good()
{
    goodB2G();
    goodG2B();
}
