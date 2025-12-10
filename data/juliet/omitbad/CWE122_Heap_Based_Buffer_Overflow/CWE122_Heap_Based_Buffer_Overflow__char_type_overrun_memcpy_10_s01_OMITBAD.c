#include "std_testcase.h"
#include <wchar.h>
void CWE122_Heap_Based_Buffer_Overflow__char_type_overrun_memcpy_10_bad()
{
    if(globalTrue)
    {
        {
            charVoid * structCharVoid = (charVoid *)malloc(sizeof(charVoid));
            if (structCharVoid == NULL) {exit(-1);}
            structCharVoid->voidSecond = (void *)SRC_STR;
            printLine((char *)structCharVoid->voidSecond);
            memcpy(structCharVoid->charFirst, SRC_STR, sizeof(*structCharVoid));
            structCharVoid->charFirst[(sizeof(structCharVoid->charFirst)/sizeof(char))-1] = '\0';
            printLine((char *)structCharVoid->charFirst);
            printLine((char *)structCharVoid->voidSecond);
            free(structCharVoid);
        }
    }
}
