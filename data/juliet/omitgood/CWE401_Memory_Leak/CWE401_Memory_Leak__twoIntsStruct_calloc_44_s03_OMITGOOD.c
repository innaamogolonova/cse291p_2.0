#include "std_testcase.h"
#include <wchar.h>
static void goodG2BSink(twoIntsStruct * data)
{
    ;
}
static void goodG2B()
{
    twoIntsStruct * data;
    void (*funcPtr) (twoIntsStruct *) = goodG2BSink;
    data = NULL;
    data = (twoIntsStruct *)ALLOCA(100*sizeof(twoIntsStruct));
    data[0].intOne = 0;
    data[0].intTwo = 0;
    printStructLine(&data[0]);
    funcPtr(data);
}
static void goodB2GSink(twoIntsStruct * data)
{
    free(data);
}
static void goodB2G()
{
    twoIntsStruct * data;
    void (*funcPtr) (twoIntsStruct *) = goodB2GSink;
    data = NULL;
    data = (twoIntsStruct *)calloc(100, sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    data[0].intOne = 0;
    data[0].intTwo = 0;
    printStructLine(&data[0]);
    funcPtr(data);
}
void CWE401_Memory_Leak__twoIntsStruct_calloc_44_good()
{
    goodG2B();
    goodB2G();
}
