#include "std_testcase.h"
#include <wchar.h>
static void goodG2B()
{
    char * data;
    char * dataBadBuffer = (char *)ALLOCA(50*sizeof(char));
    char * dataGoodBuffer = (char *)ALLOCA(100*sizeof(char));
    goto source;
source:
    data = dataGoodBuffer;
    data[0] = '\0';
    {
        char source[100];
        memset(source, 'C', 100-1);
        source[100-1] = '\0';
        strcpy(data, source);
        printLine(data);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__dest_char_alloca_cpy_18_good()
{
    goodG2B();
}
