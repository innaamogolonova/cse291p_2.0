#include "std_testcase.h"
void CWE190_Integer_Overflow__short_fscanf_add_66b_badSink(short dataArray[])
{
    short data = dataArray[2];
    {
        short result = data + 1;
        printIntLine(result);
    }
}
