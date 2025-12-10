#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__src_wchar_t_alloca_cat_65b_goodG2BSink(wchar_t * data)
{
    {
        wchar_t dest[50] = L"";
        wcscat(dest, data);
        printWLine(data);
    }
}
