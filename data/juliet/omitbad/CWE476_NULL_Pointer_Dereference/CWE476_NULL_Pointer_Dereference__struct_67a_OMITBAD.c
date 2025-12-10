#include "std_testcase.h"
#include <wchar.h>
void CWE476_NULL_Pointer_Dereference__struct_67b_badSink(CWE476_NULL_Pointer_Dereference__struct_67_structType myStruct);
void CWE476_NULL_Pointer_Dereference__struct_67_bad()
{
    twoIntsStruct * data;
    CWE476_NULL_Pointer_Dereference__struct_67_structType myStruct;
    data = NULL;
    myStruct.structFirst = data;
    CWE476_NULL_Pointer_Dereference__struct_67b_badSink(myStruct);
}
