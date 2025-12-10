#include "std_testcase.h"
#include <wchar.h>
void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_ncat_54b_badSink(wchar_t * data);
void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_ncat_54_bad()
{
    wchar_t * data;
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    wmemset(data, L'A', 100-1);
    data[100-1] = L'\0';
    CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_ncat_54b_badSink(data);
}
