#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE193_char_declare_memcpy_63b_badSink(char * * dataPtr);
void CWE121_Stack_Based_Buffer_Overflow__CWE193_char_declare_memcpy_63_bad()
{
    char * data;
    char dataBadBuffer[10];
    char dataGoodBuffer[10+1];
    data = dataBadBuffer;
    data[0] = '\0';
    CWE121_Stack_Based_Buffer_Overflow__CWE193_char_declare_memcpy_63b_badSink(&data);
}
