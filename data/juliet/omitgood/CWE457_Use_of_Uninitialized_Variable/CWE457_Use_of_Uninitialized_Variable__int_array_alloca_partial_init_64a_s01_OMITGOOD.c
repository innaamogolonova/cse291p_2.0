#include "std_testcase.h"
void CWE457_Use_of_Uninitialized_Variable__int_array_alloca_partial_init_64b_goodG2BSink(void * dataVoidPtr);
static void goodG2B()
{
    int * data;
    data = (int *)ALLOCA(10*sizeof(int));
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i] = i;
        }
    }
    CWE457_Use_of_Uninitialized_Variable__int_array_alloca_partial_init_64b_goodG2BSink(&data);
}
void CWE457_Use_of_Uninitialized_Variable__int_array_alloca_partial_init_64b_goodB2GSink(void * dataVoidPtr);
static void goodB2G()
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
    CWE457_Use_of_Uninitialized_Variable__int_array_alloca_partial_init_64b_goodB2GSink(&data);
}
void CWE457_Use_of_Uninitialized_Variable__int_array_alloca_partial_init_64_good()
{
    goodG2B();
    goodB2G();
}
