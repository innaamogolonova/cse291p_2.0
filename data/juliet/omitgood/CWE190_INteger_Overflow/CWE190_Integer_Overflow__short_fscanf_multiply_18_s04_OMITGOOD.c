#include "std_testcase.h"
static void goodB2G()
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
        if (data < (SHRT_MAX/2))
        {
            short result = data * 2;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
static void goodG2B()
{
    short data;
    data = 0;
    goto source;
source:
    data = 2;
    goto sink;
sink:
    if(data > 0)
    {
        short result = data * 2;
        printIntLine(result);
    }
}
void CWE190_Integer_Overflow__short_fscanf_multiply_18_good()
{
    goodB2G();
    goodG2B();
}
