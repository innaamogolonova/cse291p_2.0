#include "std_testcase.h"
#include <wchar.h>
void CWE401_Memory_Leak__int_calloc_64b_goodG2BSink(void * dataVoidPtr);
static void goodG2B()
{
    int * data;
    data = NULL;
    data = (int *)ALLOCA(100*sizeof(int));
    data[0] = 5;
    printIntLine(data[0]);
    CWE401_Memory_Leak__int_calloc_64b_goodG2BSink(&data);
}
void CWE401_Memory_Leak__int_calloc_64b_goodB2GSink(void * dataVoidPtr);
static void goodB2G()
{
    int * data;
    data = NULL;
    data = (int *)calloc(100, sizeof(int));
    if (data == NULL) {exit(-1);}
    data[0] = 5;
    printIntLine(data[0]);
    CWE401_Memory_Leak__int_calloc_64b_goodB2GSink(&data);
}
void CWE401_Memory_Leak__int_calloc_64_good()
{
    goodG2B();
    goodB2G();
}
