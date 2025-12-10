#include "std_testcase.h"
void CWE476_NULL_Pointer_Dereference__deref_after_check_11_bad()
{
    if(globalReturnsTrue())
    {
        {
            int *intPointer = NULL;
            if (intPointer == NULL)
            {
                printIntLine(*intPointer);
            }
        }
    }
}
