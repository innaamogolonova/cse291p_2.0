#include "std_testcase.h"
#include <wchar.h>
void CWE476_NULL_Pointer_Dereference__int_34_bad()
{
    int * data;
    CWE476_NULL_Pointer_Dereference__int_34_unionType myUnion;
    data = NULL;
    myUnion.unionFirst = data;
    {
        int * data = myUnion.unionSecond;
        printIntLine(*data);
    }
}
