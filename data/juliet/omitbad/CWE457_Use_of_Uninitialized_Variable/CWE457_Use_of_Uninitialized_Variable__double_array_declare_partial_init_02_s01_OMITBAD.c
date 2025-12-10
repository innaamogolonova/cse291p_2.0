#include "std_testcase.h"
void CWE457_Use_of_Uninitialized_Variable__double_array_declare_partial_init_02_bad()
{
    double * data;
    double dataUninitArray[10];
    data = dataUninitArray;
    if(1)
    {
        {
            int i;
            for(i=0; i<(10/2); i++)
            {
                data[i] = (double)i;
            }
        }
    }
    if(1)
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
