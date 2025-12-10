#include "std_testcase.h"
void CWE457_Use_of_Uninitialized_Variable__double_array_alloca_no_init_63b_badSink(double * * dataPtr)
{
    double * data = *dataPtr;
    {
        int i;
        for(i=0; i<10; i++)
        {
            printDoubleLine(data[i]);
        }
    }
}
