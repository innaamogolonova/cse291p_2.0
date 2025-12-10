#include "std_testcase.h"
#include <wchar.h>
int CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_22_badGlobal = 0;
char * CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_22_badSource(char * data);
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_22_bad()
{
    char * data;
    data = NULL;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_22_badGlobal = 1;
    data = CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_ncat_22_badSource(data);
    {
        char source[100];
        memset(source, 'C', 100-1);
        source[100-1] = '\0';
        strncat(data, source, 100);
        printLine(data);
        free(data);
    }
}
