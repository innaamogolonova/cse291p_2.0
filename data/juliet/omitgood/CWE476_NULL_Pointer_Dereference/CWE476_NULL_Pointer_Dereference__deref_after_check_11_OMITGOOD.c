#include "std_testcase.h"
static void good1()
{
    if(globalReturnsFalse())
    {
        printLine("Benign, fixed string");
    }
    else
    {
        {
            int *intPointer = NULL;
            if (intPointer == NULL)
            {
                printLine("pointer is NULL");
            }
        }
    }
}
static void good2()
{
    if(globalReturnsTrue())
    {
        {
            int *intPointer = NULL;
            if (intPointer == NULL)
            {
                printLine("pointer is NULL");
            }
        }
    }
}
void CWE476_NULL_Pointer_Dereference__deref_after_check_11_good()
{
    good1();
    good2();
}
