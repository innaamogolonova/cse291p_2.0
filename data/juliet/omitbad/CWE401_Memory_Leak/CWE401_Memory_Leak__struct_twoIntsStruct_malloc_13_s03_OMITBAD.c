#include "std_testcase.h"
#include <wchar.h>
void CWE401_Memory_Leak__struct_twoIntsStruct_malloc_13_bad()
{
    struct _twoIntsStruct * data;
    data = NULL;
    if(GLOBAL_CONST_FIVE==5)
    {
        data = (struct _twoIntsStruct *)malloc(100*sizeof(struct _twoIntsStruct));
        if (data == NULL) {exit(-1);}
        data[0].intOne = 0;
        data[0].intTwo = 0;
        printStructLine((twoIntsStruct *)&data[0]);
    }
    if(GLOBAL_CONST_FIVE==5)
    {
        ;
    }
}
