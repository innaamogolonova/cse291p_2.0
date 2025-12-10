#include "std_testcase.h"
#include <wchar.h>
void CWE401_Memory_Leak__char_calloc_66b_goodG2BSink(char * dataArray[])
{
    char * data = dataArray[2];
    ;
}
void CWE401_Memory_Leak__char_calloc_66b_goodB2GSink(char * dataArray[])
{
    char * data = dataArray[2];
    free(data);
}
