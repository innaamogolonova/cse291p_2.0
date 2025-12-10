#include "std_testcase.h"
#include <wchar.h>
void CWE457_Use_of_Uninitialized_Variable__wchar_t_pointer_64b_goodG2BSink(void * dataVoidPtr)
{
    wchar_t * * dataPtr = (wchar_t * *)dataVoidPtr;
    wchar_t * data = (*dataPtr);
    printWLine(data);
}
void CWE457_Use_of_Uninitialized_Variable__wchar_t_pointer_64b_goodB2GSink(void * dataVoidPtr)
{
    wchar_t * * dataPtr = (wchar_t * *)dataVoidPtr;
    wchar_t * data = (*dataPtr);
    data = L"string";
    printWLine(data);
}
