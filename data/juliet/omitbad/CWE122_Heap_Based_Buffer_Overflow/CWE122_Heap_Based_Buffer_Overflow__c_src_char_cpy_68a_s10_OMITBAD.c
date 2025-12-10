#include "std_testcase.h"
#include <wchar.h>
void CWE122_Heap_Based_Buffer_Overflow__c_src_char_cpy_68b_badSink();
void CWE122_Heap_Based_Buffer_Overflow__c_src_char_cpy_68_bad()
{
    char * data;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    memset(data, 'A', 100-1);
    data[100-1] = '\0';
    CWE122_Heap_Based_Buffer_Overflow__c_src_char_cpy_68_badData = data;
    CWE122_Heap_Based_Buffer_Overflow__c_src_char_cpy_68b_badSink();
}
