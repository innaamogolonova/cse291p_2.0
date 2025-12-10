#include "std_testcase.h"
#include <wchar.h>
static void goodB2G1()
{
    twoIntsStruct * data;
    if(1)
    {
        ;
    }
    if(0)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = (twoIntsStruct *)malloc(sizeof(twoIntsStruct));
        if (data == NULL) {exit(-1);}
        data->intOne = 5;
        data->intTwo = 6;
        printIntLine(data->intOne);
        printIntLine(data->intTwo);
    }
}
static void goodB2G2()
{
    twoIntsStruct * data;
    if(1)
    {
        ;
    }
    if(1)
    {
        data = (twoIntsStruct *)malloc(sizeof(twoIntsStruct));
        if (data == NULL) {exit(-1);}
        data->intOne = 5;
        data->intTwo = 6;
        printIntLine(data->intOne);
        printIntLine(data->intTwo);
    }
}
static void goodG2B1()
{
    twoIntsStruct * data;
    if(0)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = (twoIntsStruct *)malloc(sizeof(twoIntsStruct));
        if (data == NULL) {exit(-1);}
        data->intOne = 5;
        data->intTwo = 6;
    }
    if(1)
    {
        printIntLine(data->intOne);
        printIntLine(data->intTwo);
    }
}
static void goodG2B2()
{
    twoIntsStruct * data;
    if(1)
    {
        data = (twoIntsStruct *)malloc(sizeof(twoIntsStruct));
        if (data == NULL) {exit(-1);}
        data->intOne = 5;
        data->intTwo = 6;
    }
    if(1)
    {
        printIntLine(data->intOne);
        printIntLine(data->intTwo);
    }
}
void CWE457_Use_of_Uninitialized_Variable__struct_pointer_02_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}
