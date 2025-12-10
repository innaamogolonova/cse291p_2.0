#include "std_testcase.h"
#include <wchar.h>
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_67b_goodG2BSink(CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_67_structType myStruct);
static void goodG2B()
{
    char * data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_67_structType myStruct;
    data = NULL;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    data[0] = '\0';
    myStruct.structFirst = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_67b_goodG2BSink(myStruct);
}
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_snprintf_67_good()
{
    goodG2B();
}
