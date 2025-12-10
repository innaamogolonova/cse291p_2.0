#include "std_testcase.h"
#include <wchar.h>
void CWE457_Use_of_Uninitialized_Variable__struct_64b_badSink(void * dataVoidPtr);
void CWE457_Use_of_Uninitialized_Variable__struct_64_bad()
{
    twoIntsStruct data;
    ;
    CWE457_Use_of_Uninitialized_Variable__struct_64b_badSink(&data);
}
