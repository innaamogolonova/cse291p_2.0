#include "std_testcase.h"
#include <wchar.h>
static void goodG2B1()
{
    char * data;
    char * dataBadBuffer = (char *)ALLOCA((10)*sizeof(char));
    char * dataGoodBuffer = (char *)ALLOCA((10+1)*sizeof(char));
    switch(5)
    {
    case 6:
        printLine("Benign, fixed string");
        break;
    default:
        data = dataGoodBuffer;
        data[0] = '\0';
        break;
    }
    {
        char source[10+1] = SRC_STRING;
        strcpy(data, source);
        printLine(data);
    }
}
static void goodG2B2()
{
    char * data;
    char * dataBadBuffer = (char *)ALLOCA((10)*sizeof(char));
    char * dataGoodBuffer = (char *)ALLOCA((10+1)*sizeof(char));
    switch(6)
    {
    case 6:
        data = dataGoodBuffer;
        data[0] = '\0';
        break;
    default:
        printLine("Benign, fixed string");
        break;
    }
    {
        char source[10+1] = SRC_STRING;
        strcpy(data, source);
        printLine(data);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE193_char_alloca_cpy_15_good()
{
    goodG2B1();
    goodG2B2();
}
