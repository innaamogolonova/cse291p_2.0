#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_memmove_64b_goodG2BSink(void * dataVoidPtr);
static void goodG2B()
{
    char * data;
    char dataBadBuffer[50];
    char dataGoodBuffer[100];
    data = dataGoodBuffer;
    data[0] = '\0';
    CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_memmove_64b_goodG2BSink(&data);
}
void CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_memmove_64_good()
{
    goodG2B();
}
