#include "std_testcase.h"
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memmove_54b_badSink(int * data);
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memmove_54_bad()
{
    int * data;
    data = NULL;
    data = (int *)malloc(50*sizeof(int));
    if (data == NULL) {exit(-1);}
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memmove_54b_badSink(data);
}
