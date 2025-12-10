#include "std_testcase.h"
#include <wchar.h>
int CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_22_goodG2B1Global = 0;
int CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_22_goodG2B2Global = 0;
char * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_22_goodG2B1Source(char * data);
static void goodG2B1()
{
    char * data;
    data = NULL;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_22_goodG2B1Global = 0;
    data = CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_22_goodG2B1Source(data);
    {
        char source[100];
        memset(source, 'C', 100-1);
        source[100-1] = '\0';
        strncat(data, source, 100);
        printLine(data);
        free(data);
    }
}
char * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_22_goodG2B2Source(char * data);
static void goodG2B2()
{
    char * data;
    data = NULL;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_22_goodG2B2Global = 1;
    data = CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_22_goodG2B2Source(data);
    {
        char source[100];
        memset(source, 'C', 100-1);
        source[100-1] = '\0';
        strncat(data, source, 100);
        printLine(data);
        free(data);
    }
}
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_22_good()
{
    goodG2B1();
    goodG2B2();
}
