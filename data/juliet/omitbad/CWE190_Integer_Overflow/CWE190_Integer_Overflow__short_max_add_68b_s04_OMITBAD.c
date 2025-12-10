#include "std_testcase.h"
void CWE190_Integer_Overflow__short_max_add_68b_badSink()
{
    short data = CWE190_Integer_Overflow__short_max_add_68_badData;
    {
        short result = data + 1;
        printIntLine(result);
    }
}
