#include "std_testcase.h"
static void goodB2G()
{
    int i,k;
    int data;
    data = 0;
    for(i = 0; i < 1; i++)
    {
        data = INT_MAX;
    }
    for(k = 0; k < 1; k++)
    {
        if (data < INT_MAX)
        {
            data++;
            int result = data;
            printIntLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
static void goodG2B()
{
    int h,j;
    int data;
    data = 0;
    for(h = 0; h < 1; h++)
    {
        data = 2;
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
void CWE190_Integer_Overflow__int_max_postinc_17_good()
{
    goodB2G();
    goodG2B();
}
