#include "std_testcase.h"
void CWE457_Use_of_Uninitialized_Variable__struct_array_declare_no_init_14_bad()
{
    twoIntsStruct * data;
    twoIntsStruct dataUninitArray[10];
    data = dataUninitArray;
    if(globalFive==5)
    {
        ;
    }
    if(globalFive==5)
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
