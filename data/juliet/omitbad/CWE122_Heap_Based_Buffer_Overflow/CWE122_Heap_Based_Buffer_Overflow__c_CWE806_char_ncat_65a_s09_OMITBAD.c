#include "std_testcase.h"
#include <wchar.h>
void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncat_65b_badSink(char * data);
void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncat_65_bad()
{
    char * data;
    void (*funcPtr) (char *) = CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncat_65b_badSink;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    funcPtr(data);
}
