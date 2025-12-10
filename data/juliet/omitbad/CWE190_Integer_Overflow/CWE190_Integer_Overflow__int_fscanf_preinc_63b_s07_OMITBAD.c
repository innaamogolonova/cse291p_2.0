#include "std_testcase.h"
void CWE190_Integer_Overflow__int_fscanf_preinc_63b_badSink(int * dataPtr)
{
    int data = *dataPtr;
    {
        ++data;
        int result = data;
        printIntLine(result);
    }
}
