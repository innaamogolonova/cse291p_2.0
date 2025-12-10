#include "std_testcase.h"
#include <wchar.h>
static void badSink(twoIntsStruct * data)
{
    ;
}
void CWE401_Memory_Leak__twoIntsStruct_calloc_44_bad()
{
    twoIntsStruct * data;
    void (*funcPtr) (twoIntsStruct *) = badSink;
    data = NULL;
    data = (twoIntsStruct *)calloc(100, sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    data[0].intOne = 0;
    data[0].intTwo = 0;
    printStructLine(&data[0]);
    funcPtr(data);
}
