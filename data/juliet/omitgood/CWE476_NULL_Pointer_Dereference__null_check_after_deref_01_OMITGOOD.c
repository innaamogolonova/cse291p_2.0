#include "std_testcase.h"
static void good1()
{
    {
        int *intPointer = NULL;
        intPointer = (int *)malloc(sizeof(int));
        *intPointer = 5;
        printIntLine(*intPointer);
        *intPointer = 10;
        printIntLine(*intPointer);
    }
}
void CWE476_NULL_Pointer_Dereference__null_check_after_deref_01_good()
{
    good1();
}
