#include "std_testcase.h"
static void goodB2G()
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
                data[i] = i;
            }
        }
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
static void goodG2B()
{
    int * data;
    int dataUninitArray[10];
    data = dataUninitArray;
    while(1)
    {
        {
            int i;
            for(i=0; i<10; i++)
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
void CWE457_Use_of_Uninitialized_Variable__int_array_declare_partial_init_16_good()
{
    goodB2G();
    goodG2B();
}
