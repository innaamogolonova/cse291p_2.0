#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__char_type_overrun_memcpy_14_bad()
{
    if(globalFive==5)
    {
        {
            charVoid structCharVoid;
            structCharVoid.voidSecond = (void *)SRC_STR;
            printLine((char *)structCharVoid.voidSecond);
            memcpy(structCharVoid.charFirst, SRC_STR, sizeof(structCharVoid));
            structCharVoid.charFirst[(sizeof(structCharVoid.charFirst)/sizeof(char))-1] = '\0';
            printLine((char *)structCharVoid.charFirst);
            printLine((char *)structCharVoid.voidSecond);
        }
    }
}
