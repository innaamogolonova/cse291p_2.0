#include "std_testcase.h"
#include <wchar.h>
void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_loop_64b_badSink(void * dataVoidPtr);
void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_loop_64_bad()
{
    char * data;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_loop_64b_badSink(&data);
}
