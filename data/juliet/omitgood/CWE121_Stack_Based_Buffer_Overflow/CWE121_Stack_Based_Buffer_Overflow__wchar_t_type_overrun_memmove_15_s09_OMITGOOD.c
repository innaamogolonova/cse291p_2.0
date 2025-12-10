#include "std_testcase.h"
#include <wchar.h>
static void good1()
{
    switch(5)
    {
    case 6:
        printLine("Benign, fixed string");
        break;
    default:
    {
        charVoid structCharVoid;
        structCharVoid.voidSecond = (void *)SRC_STR;
        printWLine((wchar_t *)structCharVoid.voidSecond);
        memmove(structCharVoid.charFirst, SRC_STR, sizeof(structCharVoid.charFirst));
        structCharVoid.charFirst[(sizeof(structCharVoid.charFirst)/sizeof(wchar_t))-1] = L'\0';
        printWLine((wchar_t *)structCharVoid.charFirst);
        printWLine((wchar_t *)structCharVoid.voidSecond);
    }
    break;
    }
}
static void good2()
{
    switch(6)
    {
    case 6:
    {
        charVoid structCharVoid;
        structCharVoid.voidSecond = (void *)SRC_STR;
        printWLine((wchar_t *)structCharVoid.voidSecond);
        memmove(structCharVoid.charFirst, SRC_STR, sizeof(structCharVoid.charFirst));
        structCharVoid.charFirst[(sizeof(structCharVoid.charFirst)/sizeof(wchar_t))-1] = L'\0';
        printWLine((wchar_t *)structCharVoid.charFirst);
        printWLine((wchar_t *)structCharVoid.voidSecond);
    }
    break;
    default:
        printLine("Benign, fixed string");
        break;
    }
}
void CWE121_Stack_Based_Buffer_Overflow__wchar_t_type_overrun_memmove_15_good()
{
    good1();
    good2();
}
