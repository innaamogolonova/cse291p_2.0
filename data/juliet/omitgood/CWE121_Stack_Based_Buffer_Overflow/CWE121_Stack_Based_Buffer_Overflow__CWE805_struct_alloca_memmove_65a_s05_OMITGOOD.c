#include "std_testcase.h"
void CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_alloca_memmove_65b_goodG2BSink(twoIntsStruct * data);
static void goodG2B()
{
    twoIntsStruct * data;
    void (*funcPtr) (twoIntsStruct *) = CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_alloca_memmove_65b_goodG2BSink;
    twoIntsStruct * dataBadBuffer = (twoIntsStruct *)ALLOCA(50*sizeof(twoIntsStruct));
    twoIntsStruct * dataGoodBuffer = (twoIntsStruct *)ALLOCA(100*sizeof(twoIntsStruct));
    data = dataGoodBuffer;
    funcPtr(data);
}
void CWE121_Stack_Based_Buffer_Overflow__CWE805_struct_alloca_memmove_65_good()
{
    goodG2B();
}
