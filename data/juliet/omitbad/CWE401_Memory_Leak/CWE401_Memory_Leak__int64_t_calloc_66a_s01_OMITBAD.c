#include "std_testcase.h"
#include <wchar.h>
void CWE401_Memory_Leak__int64_t_calloc_66b_badSink(int64_t * dataArray[]);
void CWE401_Memory_Leak__int64_t_calloc_66_bad()
{
    int64_t * data;
    int64_t * dataArray[5];
    data = NULL;
    data = (int64_t *)calloc(100, sizeof(int64_t));
    if (data == NULL) {exit(-1);}
    data[0] = 5LL;
    printLongLongLine(data[0]);
    dataArray[2] = data;
    CWE401_Memory_Leak__int64_t_calloc_66b_badSink(dataArray);
}
