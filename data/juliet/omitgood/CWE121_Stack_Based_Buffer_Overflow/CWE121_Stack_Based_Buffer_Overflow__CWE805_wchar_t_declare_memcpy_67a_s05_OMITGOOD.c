#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_memcpy_67b_goodG2BSink(CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_memcpy_67_structType myStruct);
static void goodG2B()
{
    wchar_t * data;
    CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_memcpy_67_structType myStruct;
    wchar_t dataBadBuffer[50];
    wchar_t dataGoodBuffer[100];
    data = dataGoodBuffer;
    data[0] = L'\0';
    myStruct.structFirst = data;
    CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_memcpy_67b_goodG2BSink(myStruct);
}
void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_memcpy_67_good()
{
    goodG2B();
}
