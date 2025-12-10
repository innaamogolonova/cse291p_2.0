#include "std_testcase.h"
#include <wchar.h>
void CWE416_Use_After_Free__malloc_free_int_10_bad()
{
    int * data;
    data = NULL;
    if(globalTrue)
    {
        data = (int *)malloc(100*sizeof(int));
        if (data == NULL) {exit(-1);}
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i] = 5;
            }
        }
        free(data);
    }
    if(globalTrue)
    {
        printIntLine(data[0]);
    }
}
