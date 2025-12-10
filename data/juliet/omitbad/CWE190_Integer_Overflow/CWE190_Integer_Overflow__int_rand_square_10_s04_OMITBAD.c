#include "std_testcase.h"
#include <math.h>
void CWE190_Integer_Overflow__int_rand_square_10_bad()
{
    int data;
    data = 0;
    if(globalTrue)
    {
        data = RAND32();
    }
    if(globalTrue)
    {
        {
            int result = data * data;
            printIntLine(result);
        }
    }
}
