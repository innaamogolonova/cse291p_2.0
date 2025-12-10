#include <inttypes.h>
#include "std_testcase.h"
void CWE190_Integer_Overflow__int64_t_fscanf_preinc_01_bad()
{
    int64_t data;
    data = 0LL;
    fscanf (stdin, "%" SCNd64, &data);
    {
        ++data;
        int64_t result = data;
        printLongLongLine(result);
    }
}
