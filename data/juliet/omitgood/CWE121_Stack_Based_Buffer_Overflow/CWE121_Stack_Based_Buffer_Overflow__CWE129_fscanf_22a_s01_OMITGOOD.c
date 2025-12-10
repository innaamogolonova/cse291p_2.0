#include "std_testcase.h"
int CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_22_goodB2G1Global = 0;
int CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_22_goodB2G2Global = 0;
int CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_22_goodG2BGlobal = 0;
void CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_22_goodB2G1Sink(int data);
static void goodB2G1()
{
    int data;
    data = -1;
    fscanf(stdin, "%d", &data);
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_22_goodB2G1Global = 0;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_22_goodB2G1Sink(data);
}
void CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_22_goodB2G2Sink(int data);
static void goodB2G2()
{
    int data;
    data = -1;
    fscanf(stdin, "%d", &data);
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_22_goodB2G2Global = 1;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_22_goodB2G2Sink(data);
}
void CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_22_goodG2BSink(int data);
static void goodG2B()
{
    int data;
    data = -1;
    data = 7;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_22_goodG2BGlobal = 1;
    CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_22_goodG2BSink(data);
}
void CWE121_Stack_Based_Buffer_Overflow__CWE129_fscanf_22_good()
{
    goodB2G1();
    goodB2G2();
    goodG2B();
}
