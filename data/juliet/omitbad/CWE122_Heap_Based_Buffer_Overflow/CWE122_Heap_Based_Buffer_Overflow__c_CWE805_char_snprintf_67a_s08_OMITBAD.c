#include "std_testcase.h"
#include <wchar.h>
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_67b_badSink(CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_67_structType myStruct);
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_67_bad()
{
    char * data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_67_structType myStruct;
    data = NULL;
    data = (char *)malloc(50*sizeof(char));
    if (data == NULL) {exit(-1);}
    data[0] = '\0';
    myStruct.structFirst = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_67b_badSink(myStruct);
}
