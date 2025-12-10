#include "std_testcase.h"
void CWE457_Use_of_Uninitialized_Variable__struct_array_malloc_no_init_02_bad()
{
    twoIntsStruct * data;
    data = (twoIntsStruct *)malloc(10*sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    if(1)
    {
        ;
    }
    if(1)
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
