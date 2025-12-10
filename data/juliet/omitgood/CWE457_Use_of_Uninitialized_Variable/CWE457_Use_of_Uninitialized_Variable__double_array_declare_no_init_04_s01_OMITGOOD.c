#include "std_testcase.h"
static void goodB2G1()
{
    double * data;
    double dataUninitArray[10];
    data = dataUninitArray;
    if(STATIC_CONST_TRUE)
    {
        ;
    }
    if(STATIC_CONST_FALSE)
    {
        printLine("Benign, fixed string");
    }
    else
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
static void goodB2G2()
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
static void goodG2B1()
{
    double * data;
    double dataUninitArray[10];
    data = dataUninitArray;
    if(STATIC_CONST_FALSE)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        {
            int i;
            for(i=0; i<10; i++)
            {
                data[i] = (double)i;
            }
        }
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
static void goodG2B2()
{
    double * data;
    double dataUninitArray[10];
    data = dataUninitArray;
    if(STATIC_CONST_TRUE)
    {
        {
            int i;
            for(i=0; i<10; i++)
            {
                data[i] = (double)i;
            }
        }
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
void CWE457_Use_of_Uninitialized_Variable__double_array_declare_no_init_04_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}
