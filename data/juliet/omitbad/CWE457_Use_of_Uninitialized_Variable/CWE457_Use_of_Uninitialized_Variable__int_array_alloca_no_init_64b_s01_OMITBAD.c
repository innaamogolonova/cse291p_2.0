#include "std_testcase.h"
void CWE457_Use_of_Uninitialized_Variable__int_array_alloca_no_init_64b_badSink(void * dataVoidPtr)
{
    int * * dataPtr = (int * *)dataVoidPtr;
    int * data = (*dataPtr);
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i]);
        }
    }
}
