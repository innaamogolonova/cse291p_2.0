#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_cpy_54b_goodG2BSink(char * data);
static void goodG2B()
{
    char * data;
    char dataBadBuffer[50];
    char dataGoodBuffer[100];
    data = dataGoodBuffer;
    data[0] = '\0';
    CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_cpy_54b_goodG2BSink(data);
}
void CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_cpy_54_good()
{
    goodG2B();
}
