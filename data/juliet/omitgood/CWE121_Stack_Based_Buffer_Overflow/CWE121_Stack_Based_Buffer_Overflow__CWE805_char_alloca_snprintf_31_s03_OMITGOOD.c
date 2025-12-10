#include "std_testcase.h"
#include <wchar.h>
static void goodG2B()
{
    char * data;
    char * dataBadBuffer = (char *)ALLOCA(50*sizeof(char));
    char * dataGoodBuffer = (char *)ALLOCA(100*sizeof(char));
    data = dataGoodBuffer;
    data[0] = '\0';
    {
        char * dataCopy = data;
        char * data = dataCopy;
        {
            char source[100];
            memset(source, 'C', 100-1);
            source[100-1] = '\0';
            SNPRINTF(data, 100, "%s", source);
            printLine(data);
        }
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE805_char_alloca_snprintf_31_good()
{
    goodG2B();
}
