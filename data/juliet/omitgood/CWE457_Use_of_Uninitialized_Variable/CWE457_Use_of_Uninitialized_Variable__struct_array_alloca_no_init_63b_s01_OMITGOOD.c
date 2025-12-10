#include "std_testcase.h"
void CWE457_Use_of_Uninitialized_Variable__struct_array_alloca_no_init_63b_goodG2BSink(twoIntsStruct * * dataPtr)
{
    twoIntsStruct * data = *dataPtr;
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].intOne);
            printIntLine(data[i].intTwo);
        }
    }
}
void CWE457_Use_of_Uninitialized_Variable__struct_array_alloca_no_init_63b_goodB2GSink(twoIntsStruct * * dataPtr)
{
    twoIntsStruct * data = *dataPtr;
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i].intOne = i;
            data[i].intTwo = i;
        }
    }
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i].intOne);
            printIntLine(data[i].intTwo);
        }
    }
}
