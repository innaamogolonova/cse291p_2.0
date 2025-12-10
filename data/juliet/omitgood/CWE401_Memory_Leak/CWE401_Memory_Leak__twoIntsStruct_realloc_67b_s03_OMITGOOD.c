#include "std_testcase.h"
#include <wchar.h>
void CWE401_Memory_Leak__twoIntsStruct_realloc_67b_goodG2BSink(CWE401_Memory_Leak__twoIntsStruct_realloc_67_structType myStruct)
{
    twoIntsStruct * data = myStruct.structFirst;
    ;
}
void CWE401_Memory_Leak__twoIntsStruct_realloc_67b_goodB2GSink(CWE401_Memory_Leak__twoIntsStruct_realloc_67_structType myStruct)
{
    twoIntsStruct * data = myStruct.structFirst;
    free(data);
}
