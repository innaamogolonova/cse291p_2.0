#include "std_testcase.h"
#include <wchar.h>
static void goodG2B()
{
    int64_t * data;
    int64_t tmpData = 5LL;
    int64_t * *dataPtr1 = &data;
    int64_t * *dataPtr2 = &data;
    {
        int64_t * data = *dataPtr1;
        {
            data = &tmpData;
        }
        *dataPtr1 = data;
    }
    {
        int64_t * data = *dataPtr2;
        printLongLongLine(*data);
    }
}
static void goodB2G()
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
        if (data != NULL)
        {
            printLongLongLine(*data);
        }
        else
        {
            printLine("data is NULL");
        }
    }
}
void CWE476_NULL_Pointer_Dereference__int64_t_32_good()
{
    goodG2B();
    goodB2G();
}
