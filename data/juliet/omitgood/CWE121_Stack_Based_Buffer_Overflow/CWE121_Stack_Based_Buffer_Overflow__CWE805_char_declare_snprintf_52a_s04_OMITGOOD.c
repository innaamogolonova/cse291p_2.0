#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_snprintf_52b_goodG2BSink(char * data);
static void goodG2B()
{
    char * data;
    char dataBadBuffer[50];
    char dataGoodBuffer[100];
    data = dataGoodBuffer;
    data[0] = '\0';
    CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_snprintf_52b_goodG2BSink(data);
}
void CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_snprintf_52_good()
{
    goodG2B();
}
