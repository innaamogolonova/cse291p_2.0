#include "std_testcase.h"
void CWE457_Use_of_Uninitialized_Variable__double_array_declare_no_init_04_bad()
{
    double * data;
    double dataUninitArray[10];
    data = dataUninitArray;
    if(STATIC_CONST_TRUE)
    {
        ;
    }
    if(STATIC_CONST_TRUE)
    {
        {
            int i;
            for(i=0; i<10; i++)
            {
                printDoubleLine(data[i]);
            }
        }
    }
}
