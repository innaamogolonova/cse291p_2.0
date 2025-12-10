#include "std_testcase.h"
int CWE190_Integer_Overflow__short_max_square_22_badGlobal = 0;
void CWE190_Integer_Overflow__short_max_square_22_badSink(short data);
void CWE190_Integer_Overflow__short_max_square_22_bad()
{
    short data;
    data = 0;
    data = SHRT_MAX;
    CWE190_Integer_Overflow__short_max_square_22_badGlobal = 1;
    CWE190_Integer_Overflow__short_max_square_22_badSink(data);
}
