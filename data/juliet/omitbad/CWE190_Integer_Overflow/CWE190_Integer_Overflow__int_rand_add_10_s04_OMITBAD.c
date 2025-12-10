#include "std_testcase.h"
void CWE190_Integer_Overflow__int_rand_add_10_bad()
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
            int result = data + 1;
            printIntLine(result);
        }
    }
}
