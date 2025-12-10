#include "std_testcase.h"
#include <wchar.h>
void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_memcpy_67b_badSink(CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_memcpy_67_structType myStruct);
void CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_memcpy_67_bad()
{
    wchar_t * data;
    CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_memcpy_67_structType myStruct;
    wchar_t dataBadBuffer[50];
    wchar_t dataGoodBuffer[100];
    data = dataBadBuffer;
    data[0] = L'\0';
    myStruct.structFirst = data;
    CWE121_Stack_Based_Buffer_Overflow__CWE805_wchar_t_declare_memcpy_67b_badSink(myStruct);
}
