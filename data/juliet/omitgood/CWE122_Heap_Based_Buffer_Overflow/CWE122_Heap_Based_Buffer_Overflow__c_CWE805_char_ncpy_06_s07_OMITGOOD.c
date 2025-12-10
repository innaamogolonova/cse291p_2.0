#include "std_testcase.h"
#include <wchar.h>
static void goodG2B1()
{
    char * data;
    data = NULL;
    if(STATIC_CONST_FIVE!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        data[0] = '\0';
    }
    {
        char source[100];
        memset(source, 'C', 100-1);
        source[100-1] = '\0';
        strncpy(data, source, 100-1);
        data[100-1] = '\0';
        printLine(data);
        free(data);
    }
}
static void goodG2B2()
{
    char * data;
    data = NULL;
    if(STATIC_CONST_FIVE==5)
    {
        data = (char *)malloc(100*sizeof(char));
        if (data == NULL) {exit(-1);}
        data[0] = '\0';
    }
    {
        char source[100];
        memset(source, 'C', 100-1);
        source[100-1] = '\0';
        strncpy(data, source, 100-1);
        data[100-1] = '\0';
        printLine(data);
        free(data);
    }
}
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncpy_06_good()
{
    goodG2B1();
    goodG2B2();
}
