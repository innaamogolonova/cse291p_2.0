#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cpy_64b_badSink(void * dataVoidPtr);
void CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cpy_64_bad()
{
    char * data;
    char * dataBuffer = (char *)ALLOCA(100*sizeof(char));
    data = dataBuffer;
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cpy_64b_badSink(&data);
}
