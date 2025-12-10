#include "std_testcase.h"
void CWE121_Stack_Based_Buffer_Overflow__CWE129_large_53b_goodG2BSink(int data);
static void goodG2B()
{
    int data;
    data = -1;
    data = 7;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_large_53b_goodG2BSink(data);
}
void CWE121_Stack_Based_Buffer_Overflow__CWE129_large_53b_goodB2GSink(int data);
static void goodB2G()
{
    int data;
    data = -1;
    data = 10;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_large_53b_goodB2GSink(data);
}
void CWE121_Stack_Based_Buffer_Overflow__CWE129_large_53_good()
{
    goodG2B();
    goodB2G();
}
