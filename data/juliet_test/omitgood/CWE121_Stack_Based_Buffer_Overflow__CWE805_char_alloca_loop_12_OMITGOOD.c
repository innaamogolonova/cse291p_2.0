#include "std_testcase.h"
#include <wchar.h>
static void goodG2B()
{
    char * data;
    char * dataBadBuffer = (char *)ALLOCA(50*sizeof(char));
    char * dataGoodBuffer = (char *)ALLOCA(100*sizeof(char));
    if(globalReturnsTrueOrFalse())
    {
        data = dataGoodBuffer;
        data[0] = '\0';
    }
    else
    {
        data = dataGoodBuffer;
        data[0] = '\0';
    }
    {
        size_t i;
        char source[100];
        memset(source, 'C', 100-1);
        source[100-1] = '\0';
        for (i = 0; i < 100; i++)
        {
            data[i] = source[i];
        }
        data[100-1] = '\0';
        printLine(data);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE805_char_alloca_loop_12_good()
{
    goodG2B();
}
