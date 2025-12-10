#include "std_testcase.h"
void CWE190_Integer_Overflow__short_fscanf_multiply_18_bad()
{
    short data;
    data = 0;
    goto source;
source:
    fscanf (stdin, "%hd", &data);
    goto sink;
sink:
    if(data > 0)
    {
        short result = data * 2;
        printIntLine(result);
    }
}
