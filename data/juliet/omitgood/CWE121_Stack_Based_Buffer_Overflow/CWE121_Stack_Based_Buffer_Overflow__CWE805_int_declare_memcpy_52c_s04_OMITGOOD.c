#include "std_testcase.h"
void CWE121_Stack_Based_Buffer_Overflow__CWE805_int_declare_memcpy_52c_goodG2BSink(int * data)
{
    {
        int source[100] = {0};
        memcpy(data, source, 100*sizeof(int));
        printIntLine(data[0]);
    }
}
