#include "std_testcase.h"
void CWE190_Integer_Overflow__short_rand_preinc_07_bad()
{
    short data;
    data = 0;
    if(staticFive==5)
    {
        data = (short)RAND32();
    }
    if(staticFive==5)
    {
        {
            ++data;
            short result = data;
            printIntLine(result);
        }
    }
}
