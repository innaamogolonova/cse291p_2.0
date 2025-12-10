#include "std_testcase.h"
#include <wchar.h>
void CWE416_Use_After_Free__malloc_free_struct_11_bad()
{
    twoIntsStruct * data;
    data = NULL;
    if(globalReturnsTrue())
    {
        data = (twoIntsStruct *)malloc(100*sizeof(twoIntsStruct));
        if (data == NULL) {exit(-1);}
        {
            size_t i;
            for(i = 0; i < 100; i++)
            {
                data[i].intOne = 1;
                data[i].intTwo = 2;
            }
        }
        free(data);
    }
    if(globalReturnsTrue())
    {
        printStructLine(&data[0]);
    }
}
