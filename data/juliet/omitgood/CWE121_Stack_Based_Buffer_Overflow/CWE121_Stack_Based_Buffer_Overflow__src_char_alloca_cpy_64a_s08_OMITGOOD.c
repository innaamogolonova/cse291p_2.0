#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cpy_64b_goodG2BSink(void * dataVoidPtr);
static void goodG2B()
{
    char * data;
    char * dataBuffer = (char *)ALLOCA(100*sizeof(char));
    data = dataBuffer;
    memset(data, 'A', 50-1);
    data[50-1] = '\0';
    CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cpy_64b_goodG2BSink(&data);
}
void CWE121_Stack_Based_Buffer_Overflow__src_char_alloca_cpy_64_good()
{
    goodG2B();
}
