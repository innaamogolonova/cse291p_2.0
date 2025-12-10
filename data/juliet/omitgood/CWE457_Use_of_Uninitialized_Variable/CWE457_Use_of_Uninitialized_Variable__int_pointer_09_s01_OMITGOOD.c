#include "std_testcase.h"
#include <wchar.h>
static void goodB2G1()
{
    int * data;
    if(GLOBAL_CONST_TRUE)
    {
        ;
    }
    if(GLOBAL_CONST_FALSE)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = (int *)malloc(sizeof(int));
        if (data == NULL) {exit(-1);}
        *data = 5;
        printIntLine(*data);
    }
}
static void goodB2G2()
{
    int * data;
    if(GLOBAL_CONST_TRUE)
    {
        ;
    }
    if(GLOBAL_CONST_TRUE)
    {
        data = (int *)malloc(sizeof(int));
        if (data == NULL) {exit(-1);}
        *data = 5;
        printIntLine(*data);
    }
}
static void goodG2B1()
{
    int * data;
    if(GLOBAL_CONST_FALSE)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = (int *)malloc(sizeof(int));
        if (data == NULL) {exit(-1);}
        *data = 5;
    }
    if(GLOBAL_CONST_TRUE)
    {
        printIntLine(*data);
    }
}
static void goodG2B2()
{
    int * data;
    if(GLOBAL_CONST_TRUE)
    {
        data = (int *)malloc(sizeof(int));
        if (data == NULL) {exit(-1);}
        *data = 5;
    }
    if(GLOBAL_CONST_TRUE)
    {
        printIntLine(*data);
    }
}
void CWE457_Use_of_Uninitialized_Variable__int_pointer_09_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}
