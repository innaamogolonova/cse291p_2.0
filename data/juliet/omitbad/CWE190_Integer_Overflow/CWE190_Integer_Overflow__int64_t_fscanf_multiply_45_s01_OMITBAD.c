#include <inttypes.h>
#include "std_testcase.h"
static void badSink()
{
    int64_t data = CWE190_Integer_Overflow__int64_t_fscanf_multiply_45_badData;
    if(data > 0)
    {
        int64_t result = data * 2;
        printLongLongLine(result);
    }
}
void CWE190_Integer_Overflow__int64_t_fscanf_multiply_45_bad()
{
    int64_t data;
    data = 0LL;
    fscanf (stdin, "%" SCNd64, &data);
    CWE190_Integer_Overflow__int64_t_fscanf_multiply_45_badData = data;
    badSink();
}
