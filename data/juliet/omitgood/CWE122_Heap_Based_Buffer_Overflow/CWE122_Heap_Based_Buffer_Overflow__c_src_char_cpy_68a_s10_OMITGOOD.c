#include "std_testcase.h"
#include <wchar.h>
void CWE122_Heap_Based_Buffer_Overflow__c_src_char_cpy_68b_goodG2BSink();
static void goodG2B()
{
    char * data;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    memset(data, 'A', 50-1);
    data[50-1] = '\0';
    CWE122_Heap_Based_Buffer_Overflow__c_src_char_cpy_68_goodG2BData = data;
    CWE122_Heap_Based_Buffer_Overflow__c_src_char_cpy_68b_goodG2BSink();
}
void CWE122_Heap_Based_Buffer_Overflow__c_src_char_cpy_68_good()
{
    goodG2B();
}
