#include <inttypes.h>
#include "std_testcase.h"
static void goodG2B()
{
    int64_t data;
    data = 0LL;
    data = 2;
    {
        ++data;
        int64_t result = data;
        printLongLongLine(result);
    }
}
static void goodB2G()
{
    int64_t data;
    data = 0LL;
    fscanf (stdin, "%" SCNd64, &data);
    if (data < LLONG_MAX)
    {
        ++data;
        int64_t result = data;
        printLongLongLine(result);
    }
    else
    {
        printLine("data value is too large to perform arithmetic safely.");
    }
}
void CWE190_Integer_Overflow__int64_t_fscanf_preinc_01_good()
{
    goodG2B();
    goodB2G();
}
