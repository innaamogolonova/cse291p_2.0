#include "std_testcase.h"
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_52b_goodG2BSink(int data);
static void goodG2B()
{
    int data;
    data = -1;
    data = 7;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_52b_goodG2BSink(data);
}
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_52b_goodB2GSink(int data);
static void goodB2G()
{
    int data;
    data = -1;
    {
        char inputBuffer[CHAR_ARRAY_SIZE] = "";
        if (fgets(inputBuffer, CHAR_ARRAY_SIZE, stdin) != NULL)
        {
            data = atoi(inputBuffer);
        }
        else
        {
            printLine("fgets() failed.");
        }
    }
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_52b_goodB2GSink(data);
}
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_52_good()
{
    goodG2B();
    goodB2G();
}
