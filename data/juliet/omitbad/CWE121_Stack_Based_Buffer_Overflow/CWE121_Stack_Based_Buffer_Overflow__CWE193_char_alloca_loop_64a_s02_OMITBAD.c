#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE193_char_alloca_loop_64b_badSink(void * dataVoidPtr);
void CWE121_Stack_Based_Buffer_Overflow__CWE193_char_alloca_loop_64_bad()
{
    char * data;
    char * dataBadBuffer = (char *)ALLOCA((10)*sizeof(char));
    char * dataGoodBuffer = (char *)ALLOCA((10+1)*sizeof(char));
    data = dataBadBuffer;
    data[0] = '\0';
    CWE121_Stack_Based_Buffer_Overflow__CWE193_char_alloca_loop_64b_badSink(&data);
}
