#include "std_testcase.h"
#include <wchar.h>
extern int CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_22_badGlobal;
char * CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_22_badSource(char * data)
{
    if(CWE122_Heap_Based_Buffer_Overflow__c_CWE193_char_memcpy_22_badGlobal)
    {
        data = (char *)malloc(10*sizeof(char));
        if (data == NULL) {exit(-1);}
    }
    return data;
}
