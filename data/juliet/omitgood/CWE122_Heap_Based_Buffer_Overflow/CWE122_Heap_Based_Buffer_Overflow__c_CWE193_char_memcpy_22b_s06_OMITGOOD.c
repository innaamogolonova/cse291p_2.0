#include "std_testcase.h"
#include <wchar.h>
extern int CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_22_goodG2B1Global;
extern int CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_22_goodG2B2Global;
char * CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_22_goodG2B1Source(char * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_22_goodG2B1Global)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = (char *)malloc((10+1)*sizeof(char));
        if (data == NULL) {exit(-1);}
    }
    return data;
}
char * CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_22_goodG2B2Source(char * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_22_goodG2B2Global)
    {
        data = (char *)malloc((10+1)*sizeof(char));
        if (data == NULL) {exit(-1);}
    }
    return data;
}
