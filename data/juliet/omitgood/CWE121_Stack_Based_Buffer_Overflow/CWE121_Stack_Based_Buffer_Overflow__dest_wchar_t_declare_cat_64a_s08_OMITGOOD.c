#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__dest_wchar_t_declare_cat_64b_goodG2BSink(void * dataVoidPtr);
static void goodG2B()
{
    wchar_t * data;
    wchar_t dataBadBuffer[50];
    wchar_t dataGoodBuffer[100];
    data = dataGoodBuffer;
    data[0] = L'\0';
    CWE121_Stack_Based_Buffer_Overflow__dest_wchar_t_declare_cat_64b_goodG2BSink(&data);
}
void CWE121_Stack_Based_Buffer_Overflow__dest_wchar_t_declare_cat_64_good()
{
    goodG2B();
}
