#include "std_testcase.h"
#include <wchar.h>
static void goodG2B1()
{
    wchar_t * data;
    data = NULL;
    switch(5)
    {
    case 6:
        printLine("Benign, fixed string");
        break;
    default:
        data = (wchar_t *)malloc(100*sizeof(wchar_t));
        if (data == NULL) {exit(-1);}
        data[0] = L'\0';
        break;
    }
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1);
        source[100-1] = L'\0';
        memmove(data, source, 100*sizeof(wchar_t));
        data[100-1] = L'\0';
        printWLine(data);
        free(data);
    }
}
static void goodG2B2()
{
    wchar_t * data;
    data = NULL;
    switch(6)
    {
    case 6:
        data = (wchar_t *)malloc(100*sizeof(wchar_t));
        if (data == NULL) {exit(-1);}
        data[0] = L'\0';
        break;
    default:
        printLine("Benign, fixed string");
        break;
    }
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1);
        source[100-1] = L'\0';
        memmove(data, source, 100*sizeof(wchar_t));
        data[100-1] = L'\0';
        printWLine(data);
        free(data);
    }
}
void CWE122_Heap_Based_Buffer_Overflow__c_CWE805_wchar_t_memmove_15_good()
{
    goodG2B1();
    goodG2B2();
}
