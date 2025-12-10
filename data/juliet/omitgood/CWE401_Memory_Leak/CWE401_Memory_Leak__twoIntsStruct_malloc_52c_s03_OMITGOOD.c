#include "std_testcase.h"
#include <wchar.h>
void CWE401_Memory_Leak__twoIntsStruct_malloc_52c_goodG2BSink(twoIntsStruct * data)
{
    ;
}
void CWE401_Memory_Leak__twoIntsStruct_malloc_52c_goodB2GSink(twoIntsStruct * data)
{
    free(data);
}
