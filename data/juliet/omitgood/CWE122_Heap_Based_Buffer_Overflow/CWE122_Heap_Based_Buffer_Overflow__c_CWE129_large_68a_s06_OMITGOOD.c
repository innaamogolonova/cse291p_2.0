#include "std_testcase.h"
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68b_goodG2BSink();
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68b_goodB2GSink();
static void goodG2B()
{
    int data;
    data = -1;
    data = 7;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68_goodG2BData = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68b_goodG2BSink();
}
static void goodB2G()
{
    int data;
    data = -1;
    data = 10;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68_goodB2GData = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68b_goodB2GSink();
}
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_large_68_good()
{
    goodG2B();
    goodB2G();
}
