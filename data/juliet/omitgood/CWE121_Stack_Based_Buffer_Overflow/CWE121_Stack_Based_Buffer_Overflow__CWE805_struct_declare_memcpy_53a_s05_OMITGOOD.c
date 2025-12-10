#include "std_testcase.h"
void CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_memcpy_53b_goodG2BSink(twoIntsStruct * data);
static void goodG2B()
{
    twoIntsStruct * data;
    twoIntsStruct dataBadBuffer[50];
    twoIntsStruct dataGoodBuffer[100];
    data = dataGoodBuffer;
    CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_memcpy_53b_goodG2BSink(data);
}
void CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_memcpy_53_good()
{
    goodG2B();
}
