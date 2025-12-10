#include "std_testcase.h"
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memmove_54b_goodG2BSink(int * data);
static void goodG2B()
{
    int * data;
    data = NULL;
    data = (int *)malloc(100*sizeof(int));
    if (data == NULL) {exit(-1);}
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memmove_54b_goodG2BSink(data);
}
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_int_memmove_54_good()
{
    goodG2B();
}
