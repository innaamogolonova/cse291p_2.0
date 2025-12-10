#include "std_testcase.h"
#include <wchar.h>
void CWE416_Use_After_Free__malloc_free_long_06_bad()
{
    long * data;
    data = NULL;
    if(STATIC_CONST_FIVE==5)
    {
        data = (long *)malloc(100*sizeof(long));
        if (data == NULL) {exit(-1);}
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5L;
            }
        }
        free(data);
    }
    if(STATIC_CONST_FIVE==5)
    {
        printLongLine(data[0]);
    }
}
