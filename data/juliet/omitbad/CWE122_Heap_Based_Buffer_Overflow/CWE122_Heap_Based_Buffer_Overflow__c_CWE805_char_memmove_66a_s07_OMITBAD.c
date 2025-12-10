#include "std_testcase.h"
#include <wchar.h>
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memmove_66b_badSink(char * dataArray[]);
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memmove_66_bad()
{
    char * data;
    char * dataArray[5];
    data = NULL;
    data = (char *)malloc(50*sizeof(char));
    if (data == NULL) {exit(-1);}
    data[0] = '\0';
    dataArray[2] = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE805_char_memmove_66b_badSink(dataArray);
}
