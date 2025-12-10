#include "std_testcase.h"
void CWE190_Integer_Overflow__short_fscanf_postinc_51b_badSink(short data)
{
    {
        data++;
        short result = data;
        printIntLine(result);
    }
}
