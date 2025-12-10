#include "std_testcase.h"
#include <wchar.h>
void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncat_65b_goodG2BSink(char * data);
static void goodG2B()
{
    char * data;
    void (*funcPtr) (char *) = CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncat_65b_goodG2BSink;
    data = (char *)malloc(100*sizeof(char));
    if (data == NULL) {exit(-1);}
    memset(data, 'A', 50-1);
    data[50-1] = '\0';
    funcPtr(data);
}
void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_char_ncat_65_good()
{
    goodG2B();
}
