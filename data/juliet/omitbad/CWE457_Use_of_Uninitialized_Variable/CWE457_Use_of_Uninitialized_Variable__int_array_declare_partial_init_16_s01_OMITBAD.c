#include "std_testcase.h"
void CWE457_Use_of_Uninitialized_Variable__int_array_declare_partial_init_16_bad()
{
    int * data;
    int dataUninitArray[10];
    data = dataUninitArray;
    while(1)
    {
        {
            int i;
            for(i=0; i<(10/2); i++)
            {
                data[i] = i;
            }
        }
        break;
    }
    while(1)
    {
        {
            int i;
            for(i=0; i<10; i++)
            {
                printIntLine(data[i]);
            }
        }
        break;
    }
}
