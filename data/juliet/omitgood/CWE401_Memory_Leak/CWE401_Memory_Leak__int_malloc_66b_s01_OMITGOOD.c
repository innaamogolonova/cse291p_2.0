#include "std_testcase.h"
#include <wchar.h>
void CWE401_Memory_Leak__int_malloc_66b_goodG2BSink(int * dataArray[])
{
    int * data = dataArray[2];
    ;
}
void CWE401_Memory_Leak__int_malloc_66b_goodB2GSink(int * dataArray[])
{
    int * data = dataArray[2];
    free(data);
}
