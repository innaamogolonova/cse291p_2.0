#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_cpy_54b_badSink(char * data);
void CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_cpy_54_bad()
{
    char * data;
    char dataBadBuffer[50];
    char dataGoodBuffer[100];
    data = dataBadBuffer;
    data[0] = '\0';
    CWE121_Stack_Based_Buffer_Overflow__dest_char_declare_cpy_54b_badSink(data);
}
