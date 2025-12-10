#include "std_testcase.h"
#include <wchar.h>
void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_loop_64b_goodG2BSink(void * dataVoidPtr);
static void goodG2B()
{
    char * data;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    memset(data, 'A', 50-1);
    data[50-1] = '\0';
    CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_loop_64b_goodG2BSink(&data);
}
void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_loop_64_good()
{
    goodG2B();
}
