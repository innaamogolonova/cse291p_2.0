#include "std_testcase.h"
void CWE190_Integer_Overflow__int_fscanf_postinc_65b_badSink(int data)
{
    {
        data++;
        int result = data;
        printIntLine(result);
    }
}
