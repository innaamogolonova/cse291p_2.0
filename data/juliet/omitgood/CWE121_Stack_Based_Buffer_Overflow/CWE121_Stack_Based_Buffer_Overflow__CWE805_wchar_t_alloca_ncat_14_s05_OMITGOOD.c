#include "std_testcase.h"
#include <wchar.h>
static void goodG2B1()
{
    wchar_t * data;
    wchar_t * dataBadBuffer = (wchar_t *)ALLOCA(50*sizeof(wchar_t));
    wchar_t * dataGoodBuffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    if(globalFive!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        data = dataGoodBuffer;
        data[0] = L'\0';
    }
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1);
        source[100-1] = L'\0';
        wcsncat(data, source, 100);
        printWLine(data);
    }
}
static void goodG2B2()
{
    wchar_t * data;
    wchar_t * dataBadBuffer = (wchar_t *)ALLOCA(50*sizeof(wchar_t));
    wchar_t * dataGoodBuffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    if(globalFive==5)
    {
        data = dataGoodBuffer;
        data[0] = L'\0';
    }
    {
        wchar_t source[100];
        wmemset(source, L'C', 100-1);
        source[100-1] = L'\0';
        wcsncat(data, source, 100);
        printWLine(data);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_ncat_14_good()
{
    goodG2B1();
    goodG2B2();
}
