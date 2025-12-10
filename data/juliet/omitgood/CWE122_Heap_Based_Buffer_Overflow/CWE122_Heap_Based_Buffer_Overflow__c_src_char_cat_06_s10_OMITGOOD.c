#include "std_testcase.h"
#include <wchar.h>
static void goodG2B1()
{
    char * data;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    if(STATIC_CONST_FIVE!=5)
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
        strcat(dest, data);
        printLine(data);
        free(data);
    }
}
static void goodG2B2()
{
    char * data;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    if(STATIC_CONST_FIVE==5)
    {
        memset(data, 'A', 50-1);
        data[50-1] = '\0';
    }
    {
        char dest[50] = "";
        strcat(dest, data);
        printLine(data);
        free(data);
    }
}
void CWE122_Heap_Based_Buffer_Overflow__c_src_char_cat_06_good()
{
    goodG2B1();
    goodG2B2();
}
