#include "std_testcase.h"
void CWE457_Use_of_Uninitialized_Variable__double_array_alloca_partial_init_18_bad()
{
    double * data;
    data = (double *)ALLOCA(10*sizeof(double));
    goto source;
source:
    {
        int i;
        for(i=0; i<(10/2); i++)
        {
            data[i] = (double)i;
        }
    }
    goto sink;
sink:
    {
        int i;
        for(i=0; i<10; i++)
        {
            printDoubleLine(data[i]);
        }
    }
}
