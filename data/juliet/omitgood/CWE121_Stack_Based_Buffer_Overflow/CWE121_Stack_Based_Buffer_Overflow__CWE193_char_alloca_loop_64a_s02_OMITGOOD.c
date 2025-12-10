#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE193_char_alloca_loop_64b_goodG2BSink(void * dataVoidPtr);
static void goodG2B()
{
    char * data;
    char * dataBadBuffer = (char *)ALLOCA((10)*sizeof(char));
    char * dataGoodBuffer = (char *)ALLOCA((10+1)*sizeof(char));
    data = dataGoodBuffer;
    data[0] = '\0';
    CWE121_Stack_Based_Buffer_Overflow__CWE193_char_alloca_loop_64b_goodG2BSink(&data);
}
void CWE121_Stack_Based_Buffer_Overflow__CWE193_char_alloca_loop_64_good()
{
    goodG2B();
}
