#include "std_testcase.h"
void CWE190_Integer_Overflow__int_max_postinc_17_bad()
{
    int i,j;
    int data;
    data = 0;
    for(i = 0; i < 1; i++)
    {
        data = INT_MAX;
    }
    for(j = 0; j < 1; j++)
    {
        {
            data++;
            int result = data;
            printIntLine(result);
        }
    }
}
