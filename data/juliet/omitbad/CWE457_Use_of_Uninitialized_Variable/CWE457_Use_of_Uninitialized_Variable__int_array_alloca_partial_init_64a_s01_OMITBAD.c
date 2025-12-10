#include "std_testcase.h"
void CWE457_Use_of_Uninitialized_Variable__int_array_alloca_partial_init_64b_badSink(void * dataVoidPtr);
void CWE457_Use_of_Uninitialized_Variable__int_array_alloca_partial_init_64_bad()
{
    int * data;
    data = (int *)ALLOCA(10*sizeof(int));
    {
        int i;
        for(i=0; i<(10/2); i++)
        {
            data[i] = i;
        }
    }
    CWE457_Use_of_Uninitialized_Variable__int_array_alloca_partial_init_64b_badSink(&data);
}
