#include "std_testcase.h"
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_loop_54b_goodG2BSink(twoIntsStruct * data);
static void goodG2B()
{
    twoIntsStruct * data;
    data = NULL;
    data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
    if (data == NULL) {exit(-1);}
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_loop_54b_goodG2BSink(data);
}
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_struct_loop_54_good()
{
    goodG2B();
}
