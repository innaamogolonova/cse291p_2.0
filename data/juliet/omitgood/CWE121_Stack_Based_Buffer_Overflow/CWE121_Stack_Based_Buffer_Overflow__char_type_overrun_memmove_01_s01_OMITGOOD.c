#include "std_testcase.h"
#include <wchar.h>
static void good1()
{
    {
        charVoid structCharVoid;
        structCharVoid.voidSecond = (void *)SRC_STR;
        printLine((char *)structCharVoid.voidSecond);
        memmove(structCharVoid.charFirst, SRC_STR, sizeof(structCharVoid.charFirst));
        structCharVoid.charFirst[(sizeof(structCharVoid.charFirst)/sizeof(char))-1] = '\0';
        printLine((char *)structCharVoid.charFirst);
        printLine((char *)structCharVoid.voidSecond);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__char_type_overrun_memmove_01_good()
{
    good1();
}
