#include "std_testcase.h"
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_loop_54b_badSink(twoIntsStruct * data);
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_loop_54_bad()
{
    twoIntsStruct * data;
    data = NULL;
    data = (twoIntsStruct *)malloc(50*sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_loop_54b_badSink(data);
}
