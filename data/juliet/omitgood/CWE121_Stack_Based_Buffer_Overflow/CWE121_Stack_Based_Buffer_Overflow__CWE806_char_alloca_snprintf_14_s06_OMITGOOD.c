#include "std_testcase.h"
#include <wchar.h>
static void goodG2B1()
{
    char * data;
    char * dataBuffer = (char *)ALLOCA(100*sizeof(char));
    data = dataBuffer;
    if(globalFive!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        memset(data, 'A', 50-1);
        data[50-1] = '\0';
    }
    {
        char dest[50] = "";
        SNPRINTF(dest, strlen(data), "%s", data);
        printLine(data);
    }
}
static void goodG2B2()
{
    char * data;
    char * dataBuffer = (char *)ALLOCA(100*sizeof(char));
    data = dataBuffer;
    if(globalFive==5)
    {
        memset(data, 'A', 50-1);
        data[50-1] = '\0';
    }
    {
        char dest[50] = "";
        SNPRINTF(dest, strlen(data), "%s", data);
        printLine(data);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE806_char_alloca_snprintf_14_good()
{
    goodG2B1();
    goodG2B2();
}
