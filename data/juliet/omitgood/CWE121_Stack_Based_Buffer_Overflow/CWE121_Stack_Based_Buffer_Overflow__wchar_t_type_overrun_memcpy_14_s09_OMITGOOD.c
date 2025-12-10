#include "std_testcase.h"
#include <wchar.h>
static void good1()
{
    if(globalFive!=5)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        {
            charVoid structCharVoid;
            structCharVoid.voidSecond = (void *)SRC_STR;
            printWLine((wchar_t *)structCharVoid.voidSecond);
            memcpy(structCharVoid.charFirst, SRC_STR, sizeof(structCharVoid.charFirst));
            structCharVoid.charFirst[(sizeof(structCharVoid.charFirst)/sizeof(wchar_t))-1] = L'\0';
            printWLine((wchar_t *)structCharVoid.charFirst);
            printWLine((wchar_t *)structCharVoid.voidSecond);
        }
    }
}
static void good2()
{
    if(globalFive==5)
    {
        {
            charVoid structCharVoid;
            structCharVoid.voidSecond = (void *)SRC_STR;
            printWLine((wchar_t *)structCharVoid.voidSecond);
            memcpy(structCharVoid.charFirst, SRC_STR, sizeof(structCharVoid.charFirst));
            structCharVoid.charFirst[(sizeof(structCharVoid.charFirst)/sizeof(wchar_t))-1] = L'\0';
            printWLine((wchar_t *)structCharVoid.charFirst);
            printWLine((wchar_t *)structCharVoid.voidSecond);
        }
    }
}
void CWE121_Stack_Based_Buffer_Overflow__wchar_t_type_overrun_memcpy_14_good()
{
    good1();
    good2();
}
