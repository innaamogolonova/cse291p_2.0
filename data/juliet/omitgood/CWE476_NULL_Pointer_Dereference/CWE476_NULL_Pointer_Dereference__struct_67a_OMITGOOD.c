#include "std_testcase.h"
#include <wchar.h>
void CWE476_NULL_Pointer_Dereference__struct_67b_goodG2BSink(CWE476_NULL_Pointer_Dereference__struct_67_structType myStruct);
static void goodG2B()
{
    twoIntsStruct * data;
    twoIntsStruct tmpData;
    CWE476_NULL_Pointer_Dereference__struct_67_structType myStruct;
    {
        tmpData.intOne = 0;
        tmpData.intTwo = 0;
        data = &tmpData;
    }
    myStruct.structFirst = data;
    CWE476_NULL_Pointer_Dereference__struct_67b_goodG2BSink(myStruct);
}
void CWE476_NULL_Pointer_Dereference__struct_67b_goodB2GSink(CWE476_NULL_Pointer_Dereference__struct_67_structType myStruct);
static void goodB2G()
{
    twoIntsStruct * data;
    CWE476_NULL_Pointer_Dereference__struct_67_structType myStruct;
    data = NULL;
    myStruct.structFirst = data;
    CWE476_NULL_Pointer_Dereference__struct_67b_goodB2GSink(myStruct);
}
void CWE476_NULL_Pointer_Dereference__struct_67_good()
{
    goodG2B();
    goodB2G();
}
