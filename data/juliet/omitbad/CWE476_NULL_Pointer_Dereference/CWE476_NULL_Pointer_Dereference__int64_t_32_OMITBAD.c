#include "std_testcase.h"
#include <wchar.h>
void CWE476_NULL_Pointer_Dereference__int64_t_32_bad()
{
    int64_t * data;
    int64_t * *dataPtr1 = &data;
    int64_t * *dataPtr2 = &data;
    {
        int64_t * data = *dataPtr1;
        data = NULL;
        *dataPtr1 = data;
    }
    {
        int64_t * data = *dataPtr2;
        printLongLongLine(*data);
    }
}
