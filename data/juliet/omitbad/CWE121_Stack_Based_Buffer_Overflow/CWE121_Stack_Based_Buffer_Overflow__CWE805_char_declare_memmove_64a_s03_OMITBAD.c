#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_memmove_64b_badSink(void * dataVoidPtr);
void CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_memmove_64_bad()
{
    char * data;
    char dataBadBuffer[50];
    char dataGoodBuffer[100];
    data = dataBadBuffer;
    data[0] = '\0';
    CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_memmove_64b_badSink(&data);
}
