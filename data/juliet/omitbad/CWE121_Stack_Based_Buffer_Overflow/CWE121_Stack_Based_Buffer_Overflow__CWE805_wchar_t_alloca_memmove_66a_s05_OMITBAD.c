#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_memmove_66b_badSink(wchar_t * dataArray[]);
void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_memmove_66_bad()
{
    wchar_t * data;
    wchar_t * dataArray[5];
    wchar_t * dataBadBuffer = (wchar_t *)ALLOCA(50*sizeof(wchar_t));
    wchar_t * dataGoodBuffer = (wchar_t *)ALLOCA(100*sizeof(wchar_t));
    data = dataBadBuffer;
    data[0] = L'\0';
    dataArray[2] = data;
    CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_alloca_memmove_66b_badSink(dataArray);
}
