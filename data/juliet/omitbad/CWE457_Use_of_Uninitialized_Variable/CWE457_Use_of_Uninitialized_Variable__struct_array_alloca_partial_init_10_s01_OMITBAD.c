#include "std_testcase.h"
void CWE457_Use_of_Uninitialized_Variable__struct_array_alloca_partial_init_10_bad()
{
    twoIntsStruct * data;
    data = (twoIntsStruct *)ALLOCA(10*sizeof(twoIntsStruct));
    if(globalTrue)
    {
        {
            int i;
            for(i=0; i<(10/2); i++)
            {
                data[i].intOne = i;
                data[i].intTwo = i;
            }
        }
    }
    if(globalTrue)
    {
        {
            int i;
            for(i=0; i<10; i++)
            {
                printIntLine(data[i].intOne);
                printIntLine(data[i].intTwo);
            }
        }
    }
}
