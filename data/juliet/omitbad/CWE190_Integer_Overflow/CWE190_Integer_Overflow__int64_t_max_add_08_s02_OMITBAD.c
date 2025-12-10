#include "std_testcase.h"
void CWE190_Integer_Overflow__int64_t_max_add_08_bad()
{
    int64_t data;
    data = 0LL;
    if(staticReturnsTrue())
    {
        data = LLONG_MAX;
    }
    if(staticReturnsTrue())
    {
        {
            int64_t result = data + 1;
            printLongLongLine(result);
        }
    }
}
