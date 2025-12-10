#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_alloca_memcpy_63b_badSink(wchar_t * * dataPtr);
void CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_alloca_memcpy_63_bad()
{
    wchar_t * data;
    wchar_t * dataBuffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    data = dataBuffer;
    wmemset(data, L'A', 100-1);
    data[100-1] = L'\0';
    CWE121_Stack_Based_Buffer_Overflow__CWE806_wchar_t_alloca_memcpy_63b_badSink(&data);
}
