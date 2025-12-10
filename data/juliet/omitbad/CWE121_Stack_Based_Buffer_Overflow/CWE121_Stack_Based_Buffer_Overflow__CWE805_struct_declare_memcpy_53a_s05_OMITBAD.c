#include "std_testcase.h"
void CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_memcpy_53b_badSink(twoIntsStruct * data);
void CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_memcpy_53_bad()
{
    twoIntsStruct * data;
    twoIntsStruct dataBadBuffer[50];
    twoIntsStruct dataGoodBuffer[100];
    data = dataBadBuffer;
    CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_declare_memcpy_53b_badSink(data);
}
