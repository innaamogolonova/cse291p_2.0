#include "std_testcase.h"
int CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_22_badGlobal = 0;
void CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_22_badSink(int data);
void CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_22_bad()
{
    int data;
    data = -1;
    fscanf(stdin, "%d", &data);
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_22_badGlobal = 1;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_22_badSink(data);
}
