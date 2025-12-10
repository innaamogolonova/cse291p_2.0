#include "std_testcase.h"
#include <math.h>
void CWE190_Integer_Overflow__short_rand_square_10_bad()
{
    short data;
    data = 0;
    if(globalTrue)
    {
        data = (short)RAND32();
    }
    if(globalTrue)
    {
        {
            short result = data * data;
            printIntLine(result);
        }
    }
}
