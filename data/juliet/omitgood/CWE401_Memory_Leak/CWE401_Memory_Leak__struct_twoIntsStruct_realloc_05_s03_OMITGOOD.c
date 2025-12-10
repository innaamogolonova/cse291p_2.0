#include "std_testcase.h"
#include <wchar.h>
static void goodB2G1()
{
    struct _twoIntsStruct * data;
    data = NULL;
    if(staticTrue)
    {
        data = (struct _twoIntsStruct *)realloc(data, 100*sizeof(struct _twoIntsStruct));
        if (data == NULL) {exit(-1);}
        data[0].intOne = 0;
        data[0].intTwo = 0;
        printStructLine((twoIntsStruct *)&data[0]);
    }
    if(staticFalse)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        free(data);
    }
}
static void goodB2G2()
{
    struct _twoIntsStruct * data;
    data = NULL;
    if(staticTrue)
    {
        data = (struct _twoIntsStruct *)realloc(data, 100*sizeof(struct _twoIntsStruct));
        if (data == NULL) {exit(-1);}
        data[0].intOne = 0;
        data[0].intTwo = 0;
        printStructLine((twoIntsStruct *)&data[0]);
    }
    if(staticTrue)
    {
        free(data);
    }
}
static void goodG2B1()
{
    struct _twoIntsStruct * data;
    data = NULL;
    if(staticFalse)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = (struct _twoIntsStruct *)ALLOCA(100*sizeof(struct _twoIntsStruct));
        data[0].intOne = 0;
        data[0].intTwo = 0;
        printStructLine((twoIntsStruct *)&data[0]);
    }
    if(staticTrue)
    {
        ;
    }
}
static void goodG2B2()
{
    struct _twoIntsStruct * data;
    data = NULL;
    if(staticTrue)
    {
        data = (struct _twoIntsStruct *)ALLOCA(100*sizeof(struct _twoIntsStruct));
        data[0].intOne = 0;
        data[0].intTwo = 0;
        printStructLine((twoIntsStruct *)&data[0]);
    }
    if(staticTrue)
    {
        ;
    }
}
void CWE401_Memory_Leak__struct_twoIntsStruct_realloc_05_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B1();
    goodG2B2();
}
