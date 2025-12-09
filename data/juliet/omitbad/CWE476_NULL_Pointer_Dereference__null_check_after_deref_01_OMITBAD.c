#include "std_testcase.h"
void CWE476_NULL_Pointer_Dereference__null_check_after_deref_01_bad()
{
    {
        int *intPointer = NULL;
        intPointer = (int *)malloc(sizeof(int));
        *intPointer = 5;
        printIntLine(*intPointer);
        if (intPointer != NULL)
        {
            *intPointer = 10;
        }
        printIntLine(*intPointer);
    }
}
