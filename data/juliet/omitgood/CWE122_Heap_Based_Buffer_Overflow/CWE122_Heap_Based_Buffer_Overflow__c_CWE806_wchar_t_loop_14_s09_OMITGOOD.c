#include "std_testcase.h"
#include <wchar.h>
static void goodG2B1()
{
    wchar_t * data;
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    if(globalFive!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        wmemset(data, L'A', 50-1);
        data[50-1] = L'\0';
    }
    {
        wchar_t dest[50] = L"";
        size_t i, dataLen;
        dataLen = wcslen(data);
        for (i = 0; i < dataLen; i++)
        {
            dest[i] = data[i];
        }
        dest[50-1] = L'\0';
        printWLine(data);
        free(data);
    }
}
static void goodG2B2()
{
    wchar_t * data;
    data = (wchar_t *)malloc(100*sizeof(wchar_t));
    if (data == NULL) {exit(-1);}
    if(globalFive==5)
    {
        wmemset(data, L'A', 50-1);
        data[50-1] = L'\0';
    }
    {
        wchar_t dest[50] = L"";
        size_t i, dataLen;
        dataLen = wcslen(data);
        for (i = 0; i < dataLen; i++)
        {
            dest[i] = data[i];
        }
        dest[50-1] = L'\0';
        printWLine(data);
        free(data);
    }
}
void CWE122_Heap_Based_Buffer_Overflow__c_CWE806_wchar_t_loop_14_good()
{
    goodG2B1();
    goodG2B2();
}
