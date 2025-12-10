#include "std_testcase.h"
void CWE121_Stack_Based_Buffer_Overflow__CWE129_large_53b_badSink(int data);
void CWE121_Stack_Based_Buffer_Overflow__CWE129_large_53_bad()
{
    int data;
    data = -1;
    data = 10;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_large_53b_badSink(data);
}
