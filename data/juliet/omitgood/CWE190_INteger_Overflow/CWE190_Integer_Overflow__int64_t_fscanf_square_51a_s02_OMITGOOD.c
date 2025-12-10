#include "std_testcase.h"
#include <math.h>
#include <inttypes.h>
void CWE190_Integer_Overflow__int64_t_fscanf_square_51b_goodG2BSink(int64_t data);
static void goodG2B()
{
    int64_t data;
    data = 0LL;
    data = 2;
    CWE190_Integer_Overflow__int64_t_fscanf_square_51b_goodG2BSink(data);
}
void CWE190_Integer_Overflow__int64_t_fscanf_square_51b_goodB2GSink(int64_t data);
static void goodB2G()
{
    int64_t data;
    data = 0LL;
    fscanf (stdin, "%" SCNd64, &data);
    CWE190_Integer_Overflow__int64_t_fscanf_square_51b_goodB2GSink(data);
}
void CWE190_Integer_Overflow__int64_t_fscanf_square_51_good()
{
    goodG2B();
    goodB2G();
}
