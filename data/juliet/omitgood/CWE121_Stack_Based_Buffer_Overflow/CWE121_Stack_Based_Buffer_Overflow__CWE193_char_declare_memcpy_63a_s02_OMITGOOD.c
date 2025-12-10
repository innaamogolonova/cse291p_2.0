#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE193_char_declare_memcpy_63b_goodG2BSink(char * * data);
static void goodG2B()
{
    char * data;
    char dataBadBuffer[10];
    char dataGoodBuffer[10+1];
    data = dataGoodBuffer;
    data[0] = '\0';
    CWE121_Stack_Based_Buffer_Overflow__CWE193_char_declare_memcpy_63b_goodG2BSink(&data);
}
void CWE121_Stack_Based_Buffer_Overflow__CWE193_char_declare_memcpy_63_good()
{
    goodG2B();
}
