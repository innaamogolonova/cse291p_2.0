#include "std_testcase.h"
void CWE476_NULL_Pointer_Dereference__binary_if_07_bad()
{
    if(staticFive==5)
    {
        {
            twoIntsStruct *twoIntsStructPointer = NULL;
            if ((twoIntsStructPointer != NULL) & (twoIntsStructPointer->intOne == 5))
            {
                printLine("intOne == 5");
            }
        }
    }
}
