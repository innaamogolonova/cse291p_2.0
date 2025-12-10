#include "std_testcase.h"
#include <math.h>
#include <inttypes.h>
void CWE190_Integer_Overflow__int64_t_fscanf_square_51b_badSink(int64_t data);
void CWE190_Integer_Overflow__int64_t_fscanf_square_51_bad()
{
    int64_t data;
    data = 0LL;
    fscanf (stdin, "%" SCNd64, &data);
    CWE190_Integer_Overflow__int64_t_fscanf_square_51b_badSink(data);
}
