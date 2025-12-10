#include "std_testcase.h"
#include <wchar.h>
static void goodG2B1()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    if(5!=5)
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
        strcpy(dest, data);
        printLine(data);
    }
}
static void goodG2B2()
{
    char * data;
    char dataBuffer[100];
    data = dataBuffer;
    if(5==5)
    {
        memset(data, 'A', 50-1);
        data[50-1] = '\0';
    }
    {
        char dest[50] = "";
        strcpy(dest, data);
        printLine(data);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__src_char_declare_cpy_03_good()
{
    goodG2B1();
    goodG2B2();
}
