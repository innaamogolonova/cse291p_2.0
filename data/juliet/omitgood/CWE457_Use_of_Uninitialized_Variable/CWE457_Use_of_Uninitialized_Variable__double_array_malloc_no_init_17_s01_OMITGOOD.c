#include "std_testcase.h"
static void goodB2G()
{
    int i,k;
    double * data;
    data = (double *)malloc(10*sizeof(double));
    if (data == NULL) {exit(-1);}
    for(i = 0; i < 1; i++)
    {
        ;
    }
    for(k = 0; k < 1; k++)
    {
        {
            int i;
            for(i=0; i<10; i++)
            {
                data[i] = (double)i;
            }
        }
        {
            int i;
            for(i=0; i<10; i++)
            {
                printDoubleLine(data[i]);
            }
        }
    }
}
static void goodG2B()
{
    int h,j;
    double * data;
    data = (double *)malloc(10*sizeof(double));
    if (data == NULL) {exit(-1);}
    for(h = 0; h < 1; h++)
    {
        {
            int i;
            for(i=0; i<10; i++)
            {
                data[i] = (double)i;
            }
        }
    }
    for(j = 0; j < 1; j++)
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
void CWE457_Use_of_Uninitialized_Variable__double_array_malloc_no_init_17_good()
{
    goodB2G();
    goodG2B();
}
