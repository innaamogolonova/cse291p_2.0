#include "std_testcase.h"
void CWE190_Integer_Overflow__int64_t_rand_postinc_02_bad()
{
    int64_t data;
    data = 0LL;
    if(1)
    {
        data = (int64_t)RAND64();
    }
    if(1)
    {
        {
            data++;
            int64_t result = data;
            printLongLongLine(result);
        }
    }
}
