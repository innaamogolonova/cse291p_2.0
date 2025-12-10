#include "std_testcase.h"
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68b_badSink();
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68_bad()
{
    int data;
    data = -1;
    data = 10;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68_badData = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68b_badSink();
}
