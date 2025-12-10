#include "std_testcase.h"
#include <wchar.h>
static void goodG2B()
{
    int * data;
    int tmpData = 5;
    CWE476_NULL_Pointer_Dereference__int_34_unionType myUnion;
    {
        data = &tmpData;
    }
    myUnion.unionFirst = data;
    {
        int * data = myUnion.unionSecond;
        printIntLine(*data);
    }
}
static void goodB2G()
{
    int * data;
    CWE476_NULL_Pointer_Dereference__int_34_unionType myUnion;
    data = NULL;
    myUnion.unionFirst = data;
    {
        int * data = myUnion.unionSecond;
        if (data != NULL)
        {
            printIntLine(*data);
        }
        else
        {
            printLine("data is NULL");
        }
    }
}
void CWE476_NULL_Pointer_Dereference__int_34_good()
{
    goodG2B();
    goodB2G();
}
