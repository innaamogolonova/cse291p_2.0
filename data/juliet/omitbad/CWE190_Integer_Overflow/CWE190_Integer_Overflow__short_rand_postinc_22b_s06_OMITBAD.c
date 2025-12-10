#include "std_testcase.h"
extern int CWE190_Integer_Overflow__short_rand_postinc_22_badGlobal;
void CWE190_Integer_Overflow__short_rand_postinc_22_badSink(short data)
{
    if(CWE190_Integer_Overflow__short_rand_postinc_22_badGlobal)
    {
        {
            data++;
            short result = data;
            printIntLine(result);
        }
    }
}
