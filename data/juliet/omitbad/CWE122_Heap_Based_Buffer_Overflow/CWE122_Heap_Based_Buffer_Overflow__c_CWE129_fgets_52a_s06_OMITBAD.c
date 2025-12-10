#include "std_testcase.h"
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_52b_badSink(int data);
void CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_52_bad()
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
    CWE122_Heap_Based_Buffer_Overflow__c_CWE129_fgets_52b_badSink(data);
}
