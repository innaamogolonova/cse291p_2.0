#include "std_testcase.h"
void CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_alloca_memmove_65b_badSink(twoIntsStruct * data);
void CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_alloca_memmove_65_bad()
{
    twoIntsStruct * data;
    void (*funcPtr) (twoIntsStruct *) = CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_alloca_memmove_65b_badSink;
    twoIntsStruct * dataBadBuffer = (twoIntsStruct *)ALLOCA(50*sizeof(twoIntsStruct));
    twoIntsStruct * dataGoodBuffer = (twoIntsStruct *)ALLOCA(100*sizeof(twoIntsStruct));
    data = dataBadBuffer;
    funcPtr(data);
}
