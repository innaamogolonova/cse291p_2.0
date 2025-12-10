#include "std_testcase.h"
#include <wchar.h>
static void goodG2B1()
{
    char * data;
    char dataBadBuffer[10];
    char dataGoodBuffer[10+1];
    if(staticFalse)
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
        strcpy(data, source);
        printLine(data);
    }
}
static void goodG2B2()
{
    char * data;
    char dataBadBuffer[10];
    char dataGoodBuffer[10+1];
    if(staticTrue)
    {
        data = dataGoodBuffer;
        data[0] = '\0';
    }
    {
        char source[10+1] = SRC_STRING;
        strcpy(data, source);
        printLine(data);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE193_char_declare_cpy_05_good()
{
    goodG2B1();
    goodG2B2();
}
