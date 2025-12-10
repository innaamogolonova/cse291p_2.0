#include "std_testcase.h"
static void goodB2G()
{
    int * data;
    data = (int *)malloc(10*sizeof(int));
    if (data == NULL) {exit(-1);}
    goto source;
source:
    {
        int i;
        for(i=0; i<(10/2); i++)
        {
            data[i] = i;
        }
    }
    goto sink;
sink:
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
}
static void goodG2B()
{
    int * data;
    data = (int *)malloc(10*sizeof(int));
    if (data == NULL) {exit(-1);}
    goto source;
source:
    {
        int i;
        for(i=0; i<10; i++)
        {
            data[i] = i;
        }
    }
    goto sink;
sink:
    {
        int i;
        for(i=0; i<10; i++)
        {
            printIntLine(data[i]);
        }
    }
}
void CWE457_Use_of_Uninitialized_Variable__int_array_malloc_partial_init_18_good()
{
    goodB2G();
    goodG2B();
}
