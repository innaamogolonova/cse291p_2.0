#include "std_testcase.h"
int CWE190_Integer_Overflow__int_fscanf_multiply_61b_badSource(int data)
{
    fscanf(stdin, "%d", &data);
    return data;
}
