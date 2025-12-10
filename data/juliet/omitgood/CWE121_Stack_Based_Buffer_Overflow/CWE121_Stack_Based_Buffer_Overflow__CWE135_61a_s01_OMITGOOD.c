#include "std_testcase.h"
#include <wchar.h>
void * CWE121_Stack_Based_Buffer_Overflow__CWE135_61b_goodG2BSource(void * data);
static void goodG2B()
{
    void * data;
    data = NULL;
    data = CWE121_Stack_Based_Buffer_Overflow__CWE135_61b_goodG2BSource(data);
    {
        size_t dataLen = strlen((char *)data);
        void * dest = (void *)ALLOCA((dataLen+1) * 1);
        (void)strcpy(dest, data);
        printLine((char *)dest);
    }
}
void * CWE121_Stack_Based_Buffer_Overflow__CWE135_61b_goodB2GSource(void * data);
static void goodB2G()
{
    void * data;
    data = NULL;
    data = CWE121_Stack_Based_Buffer_Overflow__CWE135_61b_goodB2GSource(data);
    {
        size_t dataLen = wcslen((wchar_t *)data);
        void * dest = (void *)ALLOCA((dataLen+1) * sizeof(wchar_t));
        (void)wcscpy(dest, data);
        printWLine((wchar_t *)dest);
    }
}
void CWE121_Stack_Based_Buffer_Overflow__CWE135_61_good()
{
    goodG2B();
    goodB2G();
}
