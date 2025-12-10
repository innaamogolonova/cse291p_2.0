#include "std_testcase.h"
#include <wchar.h>
void CWE401_Memory_Leak__int64_t_calloc_66b_goodG2BSink(int64_t * dataArray[]);
static void goodG2B()
{
    int64_t * data;
    int64_t * dataArray[5];
    data = NULL;
    data = (int64_t *)ALLOCA(100*sizeof(int64_t));
    data[0] = 5LL;
    printLongLongLine(data[0]);
    dataArray[2] = data;
    CWE401_Memory_Leak__int64_t_calloc_66b_goodG2BSink(dataArray);
}
void CWE401_Memory_Leak__int64_t_calloc_66b_goodB2GSink(int64_t * dataArray[]);
static void goodB2G()
{
    int64_t * data;
    int64_t * dataArray[5];
    data = NULL;
    data = (int64_t *)calloc(100, sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    data[0] = 5LL;
    printLongLongLine(data[0]);
    dataArray[2] = data;
    CWE401_Memory_Leak__int64_t_calloc_66b_goodB2GSink(dataArray);
}
void CWE401_Memory_Leak__int64_t_calloc_66_good()
{
    goodG2B();
    goodB2G();
}
