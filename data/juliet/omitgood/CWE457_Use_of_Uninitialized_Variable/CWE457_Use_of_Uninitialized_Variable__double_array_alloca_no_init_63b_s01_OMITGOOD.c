#include "std_testcase.h"
void CWE457_Use_of_Uninitialized_Variable__double_array_alloca_no_init_63b_goodG2BSink(double * * dataPtr)
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
void CWE457_Use_of_Uninitialized_Variable__double_array_alloca_no_init_63b_goodB2GSink(double * * dataPtr)
{
    double * data = *dataPtr;
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i] = (double)i;
        }
    }
    {
        int i;
        for(i=0; i<10; i++)
        {
            printDoubleLine(data[i]);
        }
    }
}
