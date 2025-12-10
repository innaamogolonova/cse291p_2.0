#include "std_testcase.h"
#include <math.h>
void CWE190_Integer_Overflow__int_fscanf_square_52c_badSink(int data)
{
    {
        int result = data * data;
        printIntLine(result);
    }
}
