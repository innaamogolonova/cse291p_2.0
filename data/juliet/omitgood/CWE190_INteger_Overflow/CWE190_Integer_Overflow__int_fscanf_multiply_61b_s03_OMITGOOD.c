#include "std_testcase.h"
int CWE190_Integer_Overflow__int_fscanf_multiply_61b_goodG2BSource(int data)
{
    data = 2;
    return data;
}
int CWE190_Integer_Overflow__int_fscanf_multiply_61b_goodB2GSource(int data)
{
    fscanf(stdin, "%d", &data);
    return data;
}
