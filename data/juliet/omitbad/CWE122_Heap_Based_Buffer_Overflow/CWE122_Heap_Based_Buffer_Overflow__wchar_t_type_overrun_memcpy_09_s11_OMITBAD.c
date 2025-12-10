#include "std_testcase.h"
#include <wchar.h>
void CWE122_Heap_Based_Buffer_Overflow__wchar_t_type_overrun_memcpy_09_bad()
{
    if(GLOBAL_CONST_TRUE)
    {
        {
            charVoid * structCharVoid = (charVoid *)malloc(sizeof(charVoid));
            if (structCharVoid == NULL) {exit(-1);}
            structCharVoid->voidSecond = (void *)SRC_STR;
            printWLine((wchar_t *)structCharVoid->voidSecond);
            memcpy(structCharVoid->charFirst, SRC_STR, sizeof(*structCharVoid));
            structCharVoid->charFirst[(sizeof(structCharVoid->charFirst)/sizeof(wchar_t))-1] = L'\0';
            printWLine((wchar_t *)structCharVoid->charFirst);
            printWLine((wchar_t *)structCharVoid->voidSecond);
            free(structCharVoid);
        }
    }
}
