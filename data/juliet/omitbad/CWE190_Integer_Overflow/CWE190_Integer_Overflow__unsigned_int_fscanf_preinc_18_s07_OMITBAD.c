#include "std_testcase.h"
void CWE190_Integer_Overflow__unsigned_int_fscanf_preinc_18_bad()
{
    unsigned int data;
    data = 0;
    goto source;
source:
    fscanf (stdin, "%u", &data);
    goto sink;
sink:
    {
        ++data;
        unsigned int result = data;
        printUnsignedLine(result);
    }
}
