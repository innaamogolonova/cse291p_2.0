#include "std_testcase.h"
#include <wchar.h>
void CWE457_Use_of_Uninitialized_Variable__struct_64b_goodG2BSink(void * dataVoidPtr);
static void goodG2B()
{
    twoIntsStruct data;
    data.intOne = 1;
    data.intTwo = 2;
    CWE457_Use_of_Uninitialized_Variable__struct_64b_goodG2BSink(&data);
}
void CWE457_Use_of_Uninitialized_Variable__struct_64b_goodB2GSink(void * dataVoidPtr);
static void goodB2G()
{
    twoIntsStruct data;
    ;
    CWE457_Use_of_Uninitialized_Variable__struct_64b_goodB2GSink(&data);
}
void CWE457_Use_of_Uninitialized_Variable__struct_64_good()
{
    goodG2B();
    goodB2G();
}
