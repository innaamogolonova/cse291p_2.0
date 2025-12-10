#include "std_testcase.h"
#include <wchar.h>
static void good1()
{
    if(GLOBAL_CONST_FALSE)
    {
        printLine("Benign, fixed string");
    }
    else
    {
        {
            charVoid * structCharVoid = (charVoid *)malloc(sizeof(charVoid));
            if (structCharVoid == NULL) {exit(-1);}
            structCharVoid->voidSecond = (void *)SRC_STR;
            printLine((char *)structCharVoid->voidSecond);
            memmove(structCharVoid->charFirst, SRC_STR, sizeof(structCharVoid->charFirst));
            structCharVoid->charFirst[(sizeof(structCharVoid->charFirst)/sizeof(char))-1] = '\0';
            printLine((char *)structCharVoid->charFirst);
            printLine((char *)structCharVoid->voidSecond);
        }
    }
}
static void good2()
{
    if(GLOBAL_CONST_TRUE)
    {
        {
            charVoid * structCharVoid = (charVoid *)malloc(sizeof(charVoid));
            if (structCharVoid == NULL) {exit(-1);}
            structCharVoid->voidSecond = (void *)SRC_STR;
            printLine((char *)structCharVoid->voidSecond);
            memmove(structCharVoid->charFirst, SRC_STR, sizeof(structCharVoid->charFirst));
            structCharVoid->charFirst[(sizeof(structCharVoid->charFirst)/sizeof(char))-1] = '\0';
            printLine((char *)structCharVoid->charFirst);
            printLine((char *)structCharVoid->voidSecond);
        }
    }
}
void CWE122_Heap_Based_Buffer_Overflow__char_type_overrun_memmove_09_good()
{
    good1();
    good2();
}
