#include <inttypes.h>
#include "std_testcase.h"
static void goodG2BSink()
{
    int64_t data = CWE190_Integer_Overflow__int64_t_fscanf_multiply_45_goodG2BData;
    if(data > 0)
    {
        int64_t result = data * 2;
        printLongLongLine(result);
    }
}
static void goodG2B()
{
    int64_t data;
    data = 0LL;
    data = 2;
    CWE190_Integer_Overflow__int64_t_fscanf_multiply_45_goodG2BData = data;
    goodG2BSink();
}
static void goodB2GSink()
{
    int64_t data = CWE190_Integer_Overflow__int64_t_fscanf_multiply_45_goodB2GData;
    if(data > 0)
    {
        if (data < (LLONG_MAX/2))
        {
            int64_t result = data * 2;
            printLongLongLine(result);
        }
        else
        {
            printLine("data value is too large to perform arithmetic safely.");
        }
    }
}
static void goodB2G()
{
    int64_t data;
    data = 0LL;
    fscanf (stdin, "%" SCNd64, &data);
    CWE190_Integer_Overflow__int64_t_fscanf_multiply_45_goodB2GData = data;
    goodB2GSink();
}
void CWE190_Integer_Overflow__int64_t_fscanf_multiply_45_good()
{
    goodG2B();
    goodB2G();
}
