#include "std_testcase.h"
static void goodB2G()
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
static void goodG2B()
{
    double * data;
    data = (double *)ALLOCA(10*sizeof(double));
    goto source;
source:
    {
        int i;
        for(i=0; i<10; i++)
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
void CWE457_Use_of_Uninitialized_Variable__double_array_alloca_partial_init_18_good()
{
    goodB2G();
    goodG2B();
}
