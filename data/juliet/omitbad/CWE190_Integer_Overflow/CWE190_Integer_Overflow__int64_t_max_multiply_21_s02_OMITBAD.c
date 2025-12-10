#include "std_testcase.h"
static int badStatic = 0;
static void badSink(int64_t data)
{
    if(badStatic)
    {
        if(data > 0)
        {
            int64_t result = data * 2;
            printLongLongLine(result);
        }
    }
}
void CWE190_Integer_Overflow__int64_t_max_multiply_21_bad()
{
    int64_t data;
    data = 0LL;
    data = LLONG_MAX;
    badStatic = 1;
    badSink(data);
}
