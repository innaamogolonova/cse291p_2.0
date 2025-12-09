#include "std_testcase.h"
void CWE476_NULL_Pointer_Dereference__null_check_after_deref_01_bad()
{
    {
        int *intPointer = NULL;
        intPointer = (int *)malloc(sizeof(int));
        if (intPointer != NULL) // Check if memory allocation was successful
        {
            *intPointer = 5;
            printIntLine(*intPointer);
            *intPointer = 10;
            printIntLine(*intPointer);
        }
        free(intPointer); // Free allocated memory to prevent memory leak
    }
}