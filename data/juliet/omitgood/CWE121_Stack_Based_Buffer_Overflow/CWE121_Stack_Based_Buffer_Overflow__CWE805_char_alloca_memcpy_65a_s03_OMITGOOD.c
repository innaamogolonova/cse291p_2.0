#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE805_char_alloca_memcpy_65b_goodG2BSink(char * data);
static void goodG2B()
{
    char * data;
    void (*funcPtr) (char *) = CWE121_Stack_Based_Buffer_Overflow__CWE805_char_alloca_memcpy_65b_goodG2BSink;
    char * dataBadBuffer = (char *)ALLOCA(50*sizeof(char));
    char * dataGoodBuffer = (char *)ALLOCA(100*sizeof(char));
    data = dataGoodBuffer;
    data[0] = '\0';
    funcPtr(data);
}
void CWE121_Stack_Based_Buffer_Overflow__CWE805_char_alloca_memcpy_65_good()
{
    goodG2B();
}
