#include "std_testcase.h"
#include <wchar.h>
void * CWE121_Stack_Based_Buffer_Overflow__CWE135_61b_badSource(void * data);
void CWE121_Stack_Based_Buffer_Overflow__CWE135_61_bad()
{
    void * data;
    data = NULL;
    data = CWE121_Stack_Based_Buffer_Overflow__CWE135_61b_badSource(data);
    {
        size_t dataLen = strlen((char *)data);
        void * dest = (void *)ALLOCA((dataLen+1) * sizeof(wchar_t));
        (void)wcscpy(dest, data);
        printLine((char *)dest);
    }
}
