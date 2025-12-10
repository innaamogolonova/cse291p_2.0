#include "std_testcase.h"
#include <wchar.h>
static void goodG2B1()
{
    char * data;
    char * dataBadBuffer = (char *)ALLOCA((10)*sizeof(char));
    char * dataGoodBuffer = (char *)ALLOCA((10+1)*sizeof(char));
    if(globalFive!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = dataGoodBuffer;
        data[0] = '\0';
    }
    {
        char source[10+1] = SRC_STRING;
        strncpy(data, source, strlen(source) + 1);
        printLine(data);
    }
}
static void goodG2B2()
{
    char * data;
    char * dataBadBuffer = (char *)ALLOCA((10)*sizeof(char));
    char * dataGoodBuffer = (char *)ALLOCA((10+1)*sizeof(char));
    if(globalFive==5)
    {
        data = dataGoodBuffer;
        data[0] = '\0';
    }
    {
        char source[10+1] = SRC_STRING;
        strncpy(data, source, strlen(source) + 1);
        printLine(data);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE193_char_alloca_ncpy_14_good()
{
    goodG2B1();
    goodG2B2();
}
