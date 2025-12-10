#include "std_testcase.h"
#include <wchar.h>
void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_memmove_66b_goodG2BSink(wchar_t * dataArray[]);
static void goodG2B()
{
    wchar_t * data;
    wchar_t * dataArray[5];
    data = NULL;
    data = (wchar_t *)malloc((10+1)*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    dataArray[2] = data;
    CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_memmove_66b_goodG2BSink(dataArray);
}
void CWE122_Heap_Based_Buffer_Overflow__c_CWE193_wchar_t_memmove_66_good()
{
    goodG2B();
}
