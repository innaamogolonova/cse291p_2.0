#include "std_testcase.h"
#include <wchar.h>
static void badSink(char * data)
{
    {
        char source[100];
        memset(source, 'C', 100-1);
        source[100-1] = '\0';
        memcpy(data, source, 100*sizeof(char));
        data[100-1] = '\0';
        printLine(data);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE805_char_declare_memcpy_44_bad()
{
    char * data;
    void (*funcPtr) (char *) = badSink;
    char dataBadBuffer[50];
    char dataGoodBuffer[100];
    data = dataBadBuffer;
    data[0] = '\0';
    funcPtr(data);
}
