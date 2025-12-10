#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_alloca_loop_63b_goodG2BSink(wchar_t * * data);
static void goodG2B()
{
    wchar_t * data;
    wchar_t * dataBadBuffer = (wchar_t *)ALLOCA((10)*sizeof(wchar_t));
    wchar_t * dataGoodBuffer = (wchar_t *)ALLOCA((10+1)*sizeof(wchar_t));
    data = dataGoodBuffer;
    data[0] = L'\0';
    CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_alloca_loop_63b_goodG2BSink(&data);
}
void CWE121_Stack_Based_Buffer_Overflow__CWE193_wchar_t_alloca_loop_63_good()
{
    goodG2B();
}
