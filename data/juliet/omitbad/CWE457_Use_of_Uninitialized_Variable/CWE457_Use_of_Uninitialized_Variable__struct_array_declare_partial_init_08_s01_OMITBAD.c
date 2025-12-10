#include "std_testcase.h"
void CWE457_Use_of_Uninitialized_Variable__struct_array_declare_partial_init_08_bad()
{
    twoIntsStruct * data;
    twoIntsStruct dataUninitArray[10];
    data = dataUninitArray;
    if(staticReturnsTrue())
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
    if(staticReturnsTrue())
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
