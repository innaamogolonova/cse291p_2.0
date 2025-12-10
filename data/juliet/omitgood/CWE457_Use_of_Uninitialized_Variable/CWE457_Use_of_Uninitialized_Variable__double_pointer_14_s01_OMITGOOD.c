#include "std_testcase.h"
#include <wchar.h>
static void goodB2G1()
{
    double * data;
    if(globalFive==5)
    {
        ;
    }
    if(globalFive!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = (double *)malloc(sizeof(double));
        if (data == NULL) {exit(-1);}
        *data = 5.0;
        printDoubleLine(*data);
    }
}
static void goodB2G2()
{
    double * data;
    if(globalFive==5)
    {
        ;
    }
    if(globalFive==5)
    {
        data = (double *)malloc(sizeof(double));
        if (data == NULL) {exit(-1);}
        *data = 5.0;
        printDoubleLine(*data);
    }
}
static void goodG2B1()
{
    double * data;
    if(globalFive!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = (double *)malloc(sizeof(double));
        if (data == NULL) {exit(-1);}
        *data = 5.0;
    }
    if(globalFive==5)
    {
        printDoubleLine(*data);
    }
}
static void goodG2B2()
{
    double * data;
    if(globalFive==5)
    {
        data = (double *)malloc(sizeof(double));
        if (data == NULL) {exit(-1);}
        *data = 5.0;
    }
    if(globalFive==5)
    {
        printDoubleLine(*data);
    }
}
void CWE457_Use_of_Uninitialized_Variable__double_pointer_14_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}
